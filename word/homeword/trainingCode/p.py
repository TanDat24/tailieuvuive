# Placeholder for every individual
population = {}
# population size
npop = 20
# lower bound
varmin = -10
# upper bound
varmax = 10
# cost function
costfunc = sphere
# each inidivdual has position(chromosomes) and cost
for i in range(npop):
population[i] = {'position': None, 'cost': None}
for i in range(npop):
population[i]['position'] = np.random.uniform(varmin, varmax, num_var)
population[i]['cost'] = costfunc(population[i]['position'])
# cost function
def sphere(x):
return sum(x**2)
q = np.random.permutation(npop)
p1 = population[q[0]]
p2 = population[q[1]]
def roulette_wheel_selection(p):
c = np.cumsum(p)
r = sum(p) * np.random.rand()
ind = np.argwhere(r <= c)
return ind[0][0]
p1 = population[roulette_wheel_selection(probs)]
p2 = population[roulette_wheel_selection(probs)]
# Calculating probability for roulette wheel selection
beta = 1
for i in range(len(population)):
# list of all the population cost
costs.append(population[i]['cost'])
costs = np.array(costs)
avg_cost = np.mean(costs)
if avg_cost != 0:
costs = costs/avg_cost
probs = np.exp(-beta*costs)
def crossover(p1, p2):
c1 = copy.deepcopy(p1)
c2 = copy.deepcopy(p2)
alpha = np.random.uniform(0, 1, *(c1['position'].shape))
c1['position'] = alpha*p1['position'] + (1-alpha)*p2['position']
c2['position'] = alpha*p2['position'] + (1-alpha)*p1['position']
return c1, c2
def mutate(c, mu, sigma):
# mu - mutation rate. % of gene to be modified
# sigma - step size of mutation
# mutation = original gene + (step size * random number)
y = copy.deepcopy(c)
# array of True and Flase, indicating the mutation position
flag = np.random.rand(*(c['position'].shape)) <= mu
ind = np.argwhere(flag)
y['position'][ind] += sigma * np.random.randn(*ind.shape)
return y
# Evaluate first off spring
# calculate cost function of child 1
c1['cost'] = costfunc(c1['position'])
if type(bestsol_cost) == float:
# replacing best solution in every generation/iteration
if c1['cost'] < bestsol_cost:
bestsol_cost = copy.deepcopy(c1)
else:
# replacing best solution in every generation/iteration
if c1['cost'] < bestsol_cost['cost']:
bestsol_cost = copy.deepcopy(c1)
# Evaluate second off spring
if c2['cost'] < bestsol_cost['cost']:
bestsol_cost = copy.deepcopy(c2)