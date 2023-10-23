using CargoPlanner.GeneticAlgorithm;
using CargoPlanner.TSPAlgorithm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CargoPlanner.CargoEntity
{
    public class Planner
    {
        int count = 0;
        public List<Cargo> listCargo;
        public List<Truck> listTruck;
        private List<Gene> listGene = new List<Gene>();
        private AlgorithmParameter parameters;
        double curMax = double.MinValue;
        public Dictionary<int, Cargo> mapCargo = new Dictionary<int,Cargo>();
        public Dictionary<int, Truck> mapTruck = new Dictionary<int,Truck>();

        public Dictionary<Cargo, int> mapIDCargo = new Dictionary<Cargo,int>();
        public Dictionary<Truck, int> mapIDTruck = new Dictionary<Truck,int>();

        public Planner(List<Cargo> _listCargo, List<Truck> _listTruck, AlgorithmParameter _parameters)
        {
            listCargo = _listCargo;
            listTruck = _listTruck;
            parameters = _parameters;
        }
        public Planner()
        {
        }

        public Tuple<List<string>, List<Tuple<Dictionary<Truck, List<Cargo>>, double>>> Run(int numberSolution)
        {
            var result = new List<Tuple<Dictionary<Truck, List<Cargo>>, double>>();
            var bestGene = new Gene();
            Initialize();
            List<string> listLog = new List<string>();
            
            var TotalList = new List<Tuple<Gene, double>>();
            
            for (int k = 0; k < parameters.Generation; k++)
            {
                // 3 operations of genetic algorithm

                NaturalSelection();
                HybridOrganism();
                Mutation();

                for (int i = 0; i < parameters.Population; i++)
                {
                    TotalList.Add(new Tuple<Gene, double>(listGene[i], GetCost(listGene[i])));
                }
                for (int i = 0; i < parameters.Population; i++)
                {
                    string temp = "";
                    for (int j = 0; j < listCargo.Count; j++)
                    {
                        temp += listGene[i].code[j];
                    }
                    temp += "  Generation " + k + " & cost is: " + GetCost(listGene[i]);
                    listLog.Add(temp);
                }
            }

            TotalList.Sort(delegate(Tuple<Gene, double> t1, Tuple<Gene, double> t2)
            {
                return t1.Item2.CompareTo(t2.Item2);
            });

            for (int i = 0; i < numberSolution; i++)
            {
                result.Add(Refine(TotalList[i].Item1));
            }

            return new Tuple<List<string>,List<Tuple<Dictionary<Truck,List<Cargo>>,double>>>(listLog, result);
        }
      
        private void Initialize()
        {
            MappingCargo();
            MappingTruck();
            GenerateListGene();
        }
        private void GenerateListGene()
        {
            var random = new RandomUtils();
            for (int i = 0; i < parameters.Population; i++)
            {
                var gene = new Gene();
                gene.code = random.GenerateGene(listCargo.Count, listTruck.Count);
                listGene.Add(gene);
            }
        }
        private void MappingCargo()
        {
            for (int i = 0; i < listCargo.Count(); i++)
            {
                mapCargo.Add(i, listCargo[i]);
                mapIDCargo.Add(listCargo[i], i);
            }
        }
        /// <summary>
        /// mapping truck object with a integer number
        /// </summary>
        private void MappingTruck()
        {
            for (int i = 0; i < listTruck.Count(); i++)
            {
                mapTruck.Add(i, listTruck[i]);
                mapIDTruck.Add(listTruck[i], i);
            }
        }

        /// <summary>
        /// after running algorithm, get the result
        /// </summary>
        /// <param name="gene">input gen describe the data</param>
        /// <returns>planning for cargo on truck</returns>
        public Dictionary<Truck, List<Cargo>> GenerateData(Gene gene)
        {
            var result = new Dictionary<Truck, List<Cargo>>();
            foreach (var item in listTruck)
            {
                int id = mapIDTruck.First(i => i.Key == item).Value;
                var tempList = new List<Cargo>();
                for (int i = 0; i < gene.code.Count(); i++)
                {
                    if (gene.code[i] == id) tempList.Add(mapCargo.First(c => c.Key == i).Value);
                }
                result.Add(item, tempList);
            }
            return result;
        }
        /// <summary>
        /// From the input gene, find the plan of truck and cargoes
        /// </summary>
        /// <param name="gene">A gene which is a list of int</param>
        /// <returns>List of pair, include key is truck and value is the list of cargoes on it</returns>
        private Dictionary<Truck, List<Cargo>> DecodeGene(Gene gene){
            var plan = new Dictionary<Truck, List<Cargo>>();

            int[] listAssign = gene.code;
            foreach (var item in listTruck)
            {
                int truckID = mapIDTruck.First(i => i.Key == item).Value;
                var tempListCargo = new List<Cargo>();
                for (int i = 0; i < listAssign.Count(); i++)
                {
                    if (listAssign[i] == truckID)
                    {
                        var cargo = mapCargo.First(a => a.Key == i).Value;
                        tempListCargo.Add(cargo);
                    }
                }
                plan.Add(item, tempListCargo);
            }
            return plan;
        }
        public double Cost(Dictionary<Truck, List<Cargo>> plan)
        {
            double result = 0;
            #region
            foreach (var item in plan)
            {
                var tempList = FindListAddress(item.Value);
                var distanceLib = new DistanceLib();
                var listDistance = distanceLib.DistanceTable(tempList, tempList.Count);
                if (tempList.Count > 0)
                {
                    var newTSP = new TSPLinkernighan(listDistance, tempList.Count);
                    newTSP.Solve(10, 100);
                    Console.WriteLine(count++);
                    result += newTSP.getOptimalCost() * parameters.LengthOfPath;
                }
            }
            #endregion
            var numberOverVolume = OverVolumeTruck(plan);
            var numberOverWeight = OverWeightTruck(plan);
            var numberNotMatch = NumberOfNotMatchType(plan);
            int numberUsedCar = FindNumberTruck(plan);
            double distributeLevel = FindDistributeLevel(plan);
            result += (listTruck.Count - numberOverWeight.Item1) * parameters.TruckNotOverWeight +
                      numberOverWeight.Item2 * parameters.OverWeightAmount +
                      (listTruck.Count - numberOverVolume.Item1) * parameters.TruckNotOverVolume +
                      numberOverVolume.Item2 * parameters.OverVolumeAmount +
                      numberNotMatch * parameters.NumberOfNotMatch +
                      numberUsedCar * parameters.NumberOfUsedCar +
                      distributeLevel * parameters.DistributionLevel;
            return result;
        }

        public double GetCost(Gene gene)
        {
            var plan = DecodeGene(gene);
            return Cost(plan);            
        }
        /// <summary>
        /// find a list coordinate from list Cargo
        /// </summary>
        /// <param name="listCargo">list of cargo</param>
        /// <returns>list of coordination</returns>
        private List<Tuple<double, double>> FindListAddress(List<Cargo> listCargo)
        {
            List<Tuple<double, double>> result = new List<Tuple<double, double>>();
            foreach (var item in listCargo)
            {
                var temp = new Tuple<double, double>(item.longitude, item.latitude);
                if (!result.Contains(temp))
                {
                    result.Add(temp);
                }
            }
            return result;
        }
        /// <summary>
        /// check the region that the truck passes through is crowded or normal
        /// </summary>
        /// <param name="listCargo">list cargo</param>
        /// <returns>true if crowded and false if normal</returns>
        private bool CheckRegion(List<Cargo> listCargo)
        {
            for (int i = 0; i < listCargo.Count; i++) if (listCargo[i].region == "crowded") return true;
            return false;
        }
        /// <summary>
        /// find the distribute of size and weight of cargo and decide it is hard or easy to place into the truck
        /// </summary>
        /// <param name="plan"current plan></param>
        /// <returns>estimate level</returns>
        private double FindDistributeLevel(Dictionary<Truck, List<Cargo>> plan)
        {
            var result = 0.0;
            foreach (var item in plan)
            {
                var tempValue = 0.0;
                var cargoes = item.Value;
                for (int i = 0; i < cargoes.Count; i++)
                {
                    for (int j = 0; j < cargoes.Count; j++)
                    {
                        double x = Math.Abs(cargoes[i].width - cargoes[j].width);
                        double y = Math.Abs(cargoes[i].length - cargoes[j].length);
                        double z = Math.Abs(cargoes[i].height - cargoes[j].height);
                        if (!(x == 0 && y == 0 && z == 0)) 
                            tempValue += (x * y + y * z + z * x) / (x * x + y * y + z * z);
                    }
                }
                if(cargoes.Count > 0) tempValue /= cargoes.Count;
                result += tempValue;
            }
            return result;
        }

        /// <summary>
        /// find number of car that over volume when plan for the cargo
        /// </summary> 
        /// <param name="plan">current plan</param>
        /// <returns>number of trucks</returns>
        private Tuple<int, double> OverVolumeTruck(Dictionary<Truck, List<Cargo>> plan)
        {
            var result = 0;
            var overVolume = 0.0;
            foreach (var item in plan)
            {
                var ratio = CheckRegion(item.Value) ? parameters.RatioInCrowed : parameters.RatioInNormal;
                double temp = CheckVolume(item.Key, item.Value);
                if (temp < 0)
                {
                    result++;
                    overVolume += ratio * temp;
                }
            }
            return new Tuple<int, double>(result, overVolume);
        }
        /// <summary>
        /// find number of car that over weight when plan for the cargo
        /// </summary>
        /// <param name="plan">current plan</param>
        /// <returns>number of trucks</returns>
        private Tuple<int, double> OverWeightTruck(Dictionary<Truck, List<Cargo>> plan)
        {
            var result = 0;
            var overWeight = 0.0;

            foreach (var item in plan)
            {
                var ratio = CheckRegion(item.Value) ? parameters.RatioInCrowed : parameters.RatioInNormal;
                double totalWeight = 0.0;
                foreach (var cargo in item.Value)
                {
                    totalWeight += cargo.weight;
                }
                if (item.Key.allowWeight < totalWeight)
                {
                    result++;
                    overWeight += ratio*(item.Key.allowWeight - totalWeight);
                }
            }
            return new Tuple<int,double> (result, overWeight);
        }
        /// <summary>
        /// number of not match type
        /// </summary>
        /// <param name="plan">current plan</param>
        /// <returns>number of trucks</returns>
        private double NumberOfNotMatchType(Dictionary<Truck, List<Cargo>> plan)
        {
            var result = 0.0;
            foreach (var item in plan)
            {
                int temp = 0;
                var cargoes = item.Value;
                int number = cargoes.Count;
                for (int i = 0; i < number; i++)
                {
                    for (int j = i + 1; j < number; j++)
                    {
                        if (cargoes[i].type != cargoes[j].type) temp++;
                    }
                }
                result += 2 * (double)temp / (number * (number - 1));
            }
            return result;
        }
        /// <summary>
        /// find number of car that used when plan for the cargo
        /// </summary>
        /// <param name="gene">current plan</param>
        /// <returns>number of trucks</returns>
        private int FindNumberTruck(Dictionary<Truck, List<Cargo>> plan)
        {
            int result = 0;
            foreach (var item in plan)
            {
                if (item.Value.Count > 0) result++;
            }
            return result;
        }
        /// <summary>
        /// Check the current list of cargo on truck is fit or not, TRUE if OK and FALSE if not OK
        /// </summary>
        /// <param name="truck"></param>
        /// <param name="listCargo"></param>
        /// <returns></returns>
        private double CheckVolume(Truck truck, List<Cargo> listCargo)
        {
            double maxHeight = -1.0;
            double maxLength = -1.0;
            double maxWidth = -1.0;
            double totalVolume = 0.0;

            foreach (var item in listCargo)
            {
                maxHeight = Math.Max(maxHeight, item.height);
                maxLength = Math.Max(maxLength, item.length);
                maxWidth = Math.Max(maxWidth, item.width);
                totalVolume += item.height * item.length * item.width;
            }
            if (maxHeight > truck.heightCabin || maxLength > truck.lengthCabin || maxWidth > truck.widthCabin) return -1;

            if (truck.currentRemainVolume >= 0)
            {
                return (truck.currentRemainVolume - totalVolume);
            }
            else
            {
                return ((truck.allowVolume / 100) * truck.heightCabin * truck.lengthCabin * truck.widthCabin - totalVolume);
            }
        }

        private void NaturalSelection()
        {
            double F = 0;
            double[] fitness = new double[parameters.Population];
            double[] P = new double[parameters.Population];
            double[] Q = new double[parameters.Population];
            for (int i = 0; i < parameters.Population; i++)
            {
                double cost = GetCost(listGene[i]);
                F += cost;
                fitness[i] = cost;
            }
            double cur_max = double.MinValue;
            int index_max = 0;

            for (int i = 0; i < parameters.Population; i++)
            {
                if (cur_max < fitness[i])
                {
                    cur_max = fitness[i];
                    index_max = i;
                }
            }
            // find the probability of selection and the accummulation
            for (int i = 0; i < parameters.Population; i++)
            {
                P[i] = fitness[i] / F;
                if (i >= 1) Q[i] = Q[i - 1] + P[i];
                else Q[i] = P[i];
            }

            //reconstruct the population, base on the old one by removing the bad and skip the good gene

            var newGenes = new List<Gene>();
            newGenes.Add(listGene[index_max].Copy());
            for (int i = 0; i < parameters.Population - 1; i++)
            {
                var random = new RandomUtils();
                double r = random.NormalRandom();
                if (r < Q[0] || index_max == 0) newGenes.Add(listGene[0].Copy());
                else
                {
                    // find the range should add new gene
                    for (int j = 1; j < parameters.Population; j++)
                    {
                        if (Q[j - 1] <= r && r < Q[j])
                        {
                            newGenes.Add(listGene[j].Copy());
                            break;
                        }
                    }
                }
            }
            // assign again to currently genes.
            listGene = newGenes;
        }

        private void HybridOrganism()
        {
            var random = new RandomUtils();
            double r = random.NormalRandom(); // (0, 1]
            int n = (int)(r * parameters.Population);
            if (n % 2 != 0)
            {
                n += RandomUtils.GenerateStep();
            }

            // randomly make pair two genes

            var pairs = ShuffleHelper.RandomPairMatching(n / 2, parameters.Population);
            for (int i = 0; i < pairs.Count; i++)
            {
                Gene first = listGene[pairs[i].Item1];
                Gene second = listGene[pairs[i].Item2];
                int pos = new Random().Next(0, first.code.Count()-1);

                int tempMolecule = first.code[pos];
                first.code[pos] = second.code[pos];
                second.code[pos] = tempMolecule;
            }
        }

        private void Mutation()
        {
            var random = new RandomUtils();
            double r = 0.5;

            for (int i = 0; i < parameters.Population; i++)
            {
                int index = random.RandomInRange(listCargo.Count);
                var tmpRandom = new Random();
                double tmp = tmpRandom.NextDouble();
                if (tmp < r) listGene[i].code[index] = random.RandomInRange(listTruck.Count);
            }
        }

        private Tuple<Dictionary<Truck, List<Cargo>>, double> Refine(Gene gene)
        {
            var solution = GenerateData(gene);
            var listVolume = new List<double>();
            var listWeight = new List<double>();
            for(int i = 0; i < listTruck.Count; i++)
            {
                var truck = listTruck[i];
                var listCargo = solution.First(t => t.Key == truck).Value;
                var curWeight = truck.allowWeight;
                var curVolume = (truck.currentRemainVolume > 0) ? truck.currentRemainVolume : truck.allowVolume / 100 * (truck.heightCabin * truck.lengthCabin * truck.widthCabin);
                foreach (var cargo in listCargo)
                {
                    curWeight -= cargo.weight;
                    curVolume -= (cargo.width * cargo.height * cargo.length);
                }
                listVolume.Add(curVolume);
                listWeight.Add(curWeight);
            }
            int refineNumber = 0;
            while (refineNumber < parameters.Refinement)
            {
                refineNumber++;
                for (int i = 0; i < gene.code.Count(); i++)
                {
                    var cargo = mapCargo.First(c => c.Key == i).Value;
                    var curTruck = gene.code[i];
                    if (listWeight[curTruck] < 0)
                    {
                        int newTruck = -1;
                        for (int j = 0; j < listTruck.Count; j++)
                        {
                            if (listWeight[j] >= cargo.weight)
                            {
                                
                                newTruck = j;
                                break;
                            }
                        }
                        if (newTruck >= 0)
                        {
                            //swap the cargo from the old truck to the new truck
                            int oldTruck = gene.code[i];
                            listWeight[oldTruck] += cargo.weight;
                            gene.code[i] = newTruck;
                            listWeight[newTruck] -= cargo.weight;
                            break;
                        }
                    }
                }
            }
            return new Tuple<Dictionary<Truck,List<Cargo>>,double>(GenerateData(gene), GetCost(gene));
        }
    }
}
