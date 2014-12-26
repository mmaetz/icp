#include "latticeview.h"
#include <stdlib.h>

#define N 20             //Lateral number of cells
#define ImageWidth 1000  //image width
#define ImageHeight 1000 //image height


using namespace std;

main ()
{
  int lat[N*N];  //create lattice
  int icounter, jcounter; //counters
	double p = 0.5;

  for (icounter=0; icounter<N*N; icounter++) lat[icounter]=0;
  for (icounter=0; icounter<N*N; icounter++)
	{
		if(drand48()<p)
			lat[icounter]= (int)(1);
	}
  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "task2.ppm");

}
