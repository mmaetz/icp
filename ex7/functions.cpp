#include <vector>
#include <random>
#define N 50             //Lateral number of cells
#include "functions.h"
#include <iostream>

void initalize(std::vector< std::vector<bool> >& cluster, const int seed, const double p)
{
	int icounter;
	int jcounter;

	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);

  for (icounter=0; icounter<N; icounter++)
	{
		for (jcounter=0; jcounter<N; jcounter++) 
		{
			if(dis(gen) < p)
				cluster[icounter][jcounter]=1;
			else
				cluster[icounter][jcounter]=0;
		}
	}
}

int energy_diff(std::vector< std::vector<bool> >& cluster, int i, int j)
{
	int energy, energy1, energy2 = 0;
	energy1 += cluster[i][j]*cluster[period(i+1)][j];
	energy1 += cluster[i][j]*cluster[period(i-1)][j];
	energy1 += cluster[i][j]*cluster[i][period(j-1)];
	energy1 += cluster[i][j]*cluster[i][period(j+1)];

	energy2 += -cluster[i][j]*cluster[period(i+1)][j];
	energy2 += -cluster[i][j]*cluster[period(i-1)][j];
	energy2 += -cluster[i][j]*cluster[i][period(j-1)];
	energy2 += -cluster[i][j]*cluster[i][period(j+1)];

	energy = energy1-energy2;
	return energy;
}

int period(int index)
{
	switch (index) {
		case -1: 
			return N-1;
		case N:
			return 0;
		default:
			return index;
	}
}
