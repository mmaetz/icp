#include "latticeview.h"
#include <stdlib.h>

#define N 15             //Lateral number of cells
#define ImageWidth 1000  //image width
#define ImageHeight 1000 //image height


using namespace std;

main ()
{
  int lat[N*N];  //create lattice
  int icounter, jcounter; //counters

  for (icounter=0; icounter<N*N; icounter++)
    lat[icounter]= (int)(drand48()*5.0);
  Print_lattice (lat, N, N, ImageWidth, ImageHeight, "therandomcolor.ppm");

}
