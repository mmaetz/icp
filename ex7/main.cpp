#include <iostream>
#include "latticeview.h"
#include "functions.h"
#include <vector>
#include <algorithm>
#include <random>

main () {

	int icounter;
	int jcounter;

	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);

	std::vector< std::vector<bool> > cluster(N, std::vector<bool>(N));

	const int seed = 42;
	const double p = 0.6;

	initalize(cluster, seed, p);
	Print_lattice (cluster, N, N, ImageWidth, ImageHeight, "random1.ppm");

	if( spin_energy(cluster, icounter, jcounter) < dis(gen)  )
	spin_energy(cluster, icounter, jcounter) << std::endl;
}
