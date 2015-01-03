#include <iostream>
#include "latticeview.h"
#include "functions.h"
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

main () {

	int icounter;
	int jcounter;

	double k = 1;
	double T = 1;

	const int seed_occ = 1;
	const int seed_pos = 2;
	const int seed_en = 3;
	const double p = 0.6;

	std::mt19937 gen_pos(seed_pos);
	std::mt19937 gen_en(seed_en);
	std::uniform_real_distribution<double> en(0,1);
	std::uniform_int_distribution<> pos(0,N-1);

	std::vector< std::vector<bool> > cluster(N, std::vector<bool>(N));

	initalize(cluster, seed_occ, p);
	Print_lattice (cluster, N, N, ImageWidth, ImageHeight, "random1.ppm");

	int steps = 3000000;
	int i,j;
	// ferromagnetism 1 or -1
	int ferro = -1;

	for(icounter = 0; icounter < steps; icounter++)
	{
		i = pos(gen_pos);
		j = pos(gen_pos);
		int this_energy = energy_diff(cluster, i, j, ferro);
		if( this_energy < 0 )
			flip(cluster, i, j);
		else
		{
			if( std::min(double(1),exp(-double(this_energy)/(k*T))) >= en(gen_en))
			{
				flip(cluster, i, j);
			}
		}

	}

	Print_lattice (cluster, N, N, ImageWidth, ImageHeight, "random2.ppm");
}
