#include <iostream>
#include <algorithm>
#include <cmath>
#include "functions.h"
#include "latticeview.h"
#include <stdlib.h>

#define N 50             //Lateral number of cells
#define ImageWidth 400  //image width
#define ImageHeight 400 //image height

using namespace std;

main () {

const double pi = 4 * atan(1.0);

//	cout << " Random Walk Simulation of Diffusion Limited Aggregation\n"
//		<< " -------------------------------------------------------\n"
//		<< " Enter number of particles to simulate: ";
//	int n;
//	cin >> n;

	// initialize random generator
	int seed = 42;
	// create lattice and add site at center
	initialize(N);
	// cluster has one occupied site
	int sites = 1;
	// count number of failed walks
	int failedWalks = 0;
//	while(sites < N) {
//		// walk succeeded
//		if (randomWalk()) {
//			++sites;
//			if (sites % 10 == 0)
//				cout << sites << " " << flush;
//		}
//		else
//			++failedWalks;
//	}
//	cout << " Done\n Number of failed walks = " << failedWalks << endl;
//	string name("dla.data");
//	writeCluster(name);
//	cout << " DLA cluster saved in file " << name << endl;
  Print_lattice (cluster, N, N, ImageWidth, ImageHeight, "test.ppm");

}
