import pygame, sys, random

def draw_floor():
    screen.blit(floor_surface,(floor_x_pos,422))
    screen.blit(floor_surface,(floor_x_pos + 288,422))

def create_pipe():
    random_pipes_los = random.choice(pipe_height)
    bottom_pipe = pipe_surface.get_rect(midtop = (300,random_pipes_los))
    top_pipe = pipe_surface.get_rect(midbottom = (300,random_pipes_los - 150))
    return bottom_pipe, top_pipe

def move_pipe(pipes):
    for pipe in pipes:
        pipe.centerx -= 4
    return pipes

def draw_pipes(pipes):
    for pipe in pipes:
        if pipe.bottom >= 512:
            screen.blit(pipe_surface,pipe)
        else:
            flip_pipe = pygame.transform.flip(pipe_surface,False,True)
            screen.blit(flip_pipe,pipe)

def check_collision(pipes):
    for pipe in pipes:
        if bird_rect.colliderect(pipe):
            death_sound.play()
            return False
    if bird_rect.top <= -100 or bird_rect.bottom >= 450:
        die_sound.play()
        return False

    return True

def rotate_bird(bird):
    new_bird = pygame.transform.rotozoom(bird,-bird_movement*3,1)
    return new_bird

def bird_animation():
    new_bird = bird_frames[bird_index]
    new_bird_rect = new_bird.get_rect(center = (100,bird_rect.centery))
    return new_bird,new_bird_rect

def score_display(game_state):
    if game_state == 'main_game':
        score_surface = game_font.render(str(int(score)),True,(255,255,255))
        score_rect = score_surface.get_rect(center = (144, 50))
        screen.blit(score_surface,score_rect)
    if game_state == 'game_over':
        score_surface = game_font.render(f'Score: {int(score)}',True,(255,255,255))
        score_rect = score_surface.get_rect(center = (144, 50))
        screen.blit(score_surface,score_rect)

        high_score_surface = game_font.render(f'High Score: {int(high_score)}',True,(255,255,255))
        high_score_rect = high_score_surface.get_rect(center = (144, 400))
        screen.blit(high_score_surface,high_score_rect)

def score_update(score, high_score):
    if score > high_score:
        high_score = score
    return high_score

# pygame.mixer.pre_init(frequency = 44100, size = 16, channels = 1, buffer = 400)
pygame.init()

screen = pygame.display.set_mode((288,512))
icon_title = pygame.image.load('assets/yellowbird-midflap.png')
pygame.display.set_caption('Flappy Bird')
pygame.display.set_icon(icon_title)

clock = pygame.time.Clock()
game_font = pygame.font.Font('04B_19.TTF',20)

# background
bg_surface = pygame.image.load('assets/background-day.png')

# floor
floor_surface = pygame.image.load('assets/base.png')
floor_x_pos = 0

# Cute bird
bird_downflap = pygame.image.load('assets/yellowbird-downflap.png').convert_alpha()
bird_midflap = pygame.image.load('assets/yellowbird-midflap.png').convert_alpha()
bird_upflap = pygame.image.load('assets/yellowbird-upflap.png').convert_alpha()
bird_frames = [bird_downflap,bird_midflap,bird_upflap]
bird_index = 0
bird_surface = bird_frames[bird_index]
bird_rect = bird_surface.get_rect(center = (90,256))
BIRDFLAP = pygame.USEREVENT + 1
pygame.time.set_timer(BIRDFLAP,200)

# bird_surface = pygame.image.load('assets/yellowbird-midflap.png').convert_alpha()
# bird_rect = bird_surface.get_rect(center = (90,256))

# Pipes
pipe_surface = pygame.image.load('assets/pipe-green.png')
pipe_list = []
pipe_height = [200, 300, 350]
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE,1000)

# Game welcome
message_surface = pygame.image.load('assets/message.png').convert_alpha()
message_rect = message_surface.get_rect(center = (144,256))

# Game Variables
gravity = 0.25
bird_movement = 0
game_active = False
score = 0
high_score = 0
game_state = True
game_over_surface = pygame.image.load('assets/gameover.png').convert_alpha()
game_over_rect = game_over_surface.get_rect(center = (144,256))

# Sound game
flap_sound = pygame.mixer.Sound('sound/sfx_wing.wav')
death_sound = pygame.mixer.Sound('sound/sfx_hit.wav')
score_sound = pygame.mixer.Sound('sound/sfx_point.wav')
die_sound = pygame.mixer.Sound('sound/sfx_die.wav')
score_sound_countdown = 100

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and game_active:
                flap_sound.play()
                bird_movement = 0
                bird_movement -= 6
            if event.key == pygame.K_SPACE and game_active == False:
                game_active = True
                game_state = False
                bird_rect.center = (90,256)
                pipe_list.clear()
                bird_movement = 0
                score = 0

        if event.type == SPAWNPIPE:
            pipe_list.extend(create_pipe())
        if event.type == BIRDFLAP:
            if bird_index < 2:
                bird_index += 1
            else:
                bird_index = 0

            bird_surface,bird_rect = bird_animation()

    screen.blit(bg_surface,(0,0))

    if game_active:
        # Bird
        bird_movement += gravity
        rotated_bird = rotate_bird(bird_surface)
        bird_rect.centery += bird_movement
        screen.blit(rotated_bird,bird_rect)

        # Pipe
        pipe_list = move_pipe(pipe_list)
        draw_pipes(pipe_list)

        game_active = check_collision(pipe_list)

        score += 0.01
        score_sound_countdown -= 1
        score_display('main_game')
        if score_sound_countdown <= 0:
            score_sound.play()
            score_sound_countdown = 100
    else:
        if game_state:
            screen.blit(message_surface,message_rect)
        else:
            screen.blit(game_over_surface,game_over_rect)
            high_score = score_update(score, high_score)
            score_display('game_over')

    # Floor
    floor_x_pos -= 1
    draw_floor()
    if floor_x_pos <= -288:
        floor_x_pos = 0


    pygame.display.update()
    clock.tick(80)