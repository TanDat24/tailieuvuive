var canvas = document.getElementById("gamezone");
var context = canvas.getContext("2d");
var scoreShow = document.getElementById("score");

var birding = new Image();
var hinhNenChinh = new Image();
var ongTren = new Image();
var ongDuoi = new Image();
birding.src = "anh/Frame 11.png";
hinhNenChinh.src = "anh/anhnen.png";
ongTren.src = "anh/ongTren.png";
ongDuoi.src = "anh/ongDuoi.png";

var score = 0;
var khoangCachOng = 150;
var khoangCachDenOngDuoi;
var bird = {
  x: hinhNenChinh.width / 5,
  y: hinhNenChinh.height / 2,
};

var ong = [];
ong[0] = {
  x: canvas.width,
  y: 0,
};

function run() {
  context.drawImage(hinhNenChinh, 0, 0);
  context.drawImage(birding, bird.x, bird.y);

  for (var i = 0; i < ong.length; i++) {
    khoangCachDenOngDuoi = ongTren.height + khoangCachOng;
    context.drawImage(ongTren, ong[i].x, ong[i].y);
    context.drawImage(ongDuoi, ong[i].x, ong[i].y + khoangCachDenOngDuoi);
    ong[i].x -= 5;

    if (ong[i].x == canvas.width / 2) {
      ong.push({
        x: canvas.width,
        y: Math.floor(Math.random() * ongTren.height) - ongTren.height - 5,
      });
    }
    if (ong[i].x == 0) ong.splice(0, 0);

    if (ong[i].x == bird.x) score++;
    if(bird.y+birding.height==canvas.height||
      bird.x+birding.width>= ong[i].x && bird.x <= ong[i].x +ongTren.width
      && (bird.y<=ong[i].y+ongTren.height||
      bird.y +birding.height>= ong[i].y+ khoangCachDenOngDuoi)    
      ){
          return;
      }   
    }
  scoreShow.innerHTML = "score: " + score;

  bird.y += 3;
  requestAnimationFrame(run);
}
document.addEventListener("keydown", function () {
  bird.y -= 50;
});
run();
