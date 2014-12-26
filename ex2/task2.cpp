#include "latticeview.h"
#include <stdlib.h>

#define N 50             //Lateral number of cells
#define ImageWidth 500  //image width
#define ImageHeight 500 //image height


using namespace std;

main ()
{
  int lat[N*N];  //create lattice
	int temp_lat[N*N];
  int icounter, jcounter; //counters
	double p = 0.5;

  for (icounter=0; icounter<N*N; icounter++) lat[icounter]=0;
		for (icounter=0; icounter<N*N; icounter++)
		{
			if(drand48()<p)
				lat[icounter]= 1;
		}
  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "task2-1.ppm");
	for (icounter = 0; icounter<N; icounter++)
	{
		if(lat[icounter] == 1)
			lat[icounter] = 2;
	}

	bool burn=1;
	bool reach=0;
	int giter = 0;
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
		giter++;
		for(icounter = N*N-N; icounter < N*N; icounter++)
		{
			if(lat[icounter]==2)
			{
				burn=0;
				reach=1;
				cout << "The fire does the reach other end and the number of steps was:" << endl;
				cout << giter << endl;
			}
		}
	}
	if(!reach)
	{
		cout << "The fire does not reach the other end and the number of steps was:" << endl;
		cout << giter << endl;
	}

  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "task2-2.ppm");

}
