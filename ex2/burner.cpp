#include "latticeview.h"
#include <random>

#define N 503             //Lateral number of cells
#define ImageWidth 500  //image width
#define ImageHeight 500 //image height

using namespace std;

void burner (double p, int seed, int& timesteps, bool& reach)
{
  int lat[N*N];  //create lattice
	int temp_lat[N*N];
  int icounter, jcounter; //counters
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);

  for (icounter=0; icounter<N*N; icounter++) lat[icounter]=0;
		for (icounter=0; icounter<N*N; icounter++)
		{
			if(dis(gen)<p)
				lat[icounter]= 1;
		}
//  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "task3-1.ppm");
	for (icounter = 0; icounter<N; icounter++)
	{
		if(lat[icounter] == 1)
			lat[icounter] = 2;
	}

	bool burn=1;
	while(burn)
	{
		burn=0;
		for (icounter = 0; icounter < N*N; icounter++)
			if(lat[icounter] == 2)
			{
				if(icounter > 0 && lat[icounter - 1] == 1)
				{
					lat[icounter - 1] = 4;
					burn=1;
				}
				if(icounter < N*N && lat[icounter + 1] == 1)
				{
					lat[icounter + 1] = 4;
					burn=1;
				}
				if(icounter<N*N-N && lat[icounter + N] == 1)
				{
					lat[icounter+N] = 4;
					burn=1;
				}
				if(icounter > N && lat[icounter - N] == 1)
				{
					lat[icounter-N] = 4;
					burn=1;
				}
			}

		for (icounter = 0; icounter < N*N; icounter++)
		{
			if(lat[icounter] == 2)
				lat[icounter] = 3;
			if(lat[icounter] == 4)
				lat[icounter] = 2;
		}
		timesteps++;
		for(icounter = N*N-N; icounter < N*N; icounter++)
		{
			if(lat[icounter]==2)
			{
				burn=0;
				reach=1;
				break;
			}
		}
	}

//  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "task3-2.ppm");
}
