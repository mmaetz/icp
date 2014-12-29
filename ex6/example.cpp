#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "random.hpp"
using namespace cpl;

int seed;

// value of pi
const double pi = 4 * atan(1.0);

// number of lattice sites in x or y
int L; 
// 2d array of sites bolinging to cluster
vector< vector<bool> > cluster;

// test wether site is on lattice
bool onLattice(int x, int y) {
	int i = y + (L - 1) / 2;
	int j = x + (L -1 ) / 2;
	return i >= 0 && i < L && j >= 0 && j < L;
}

// test wether site is occupied
bool occupied(int x, int y) {
	if (!onLattice(x, y))
		return false;
	int center = (L - 1) / 2;
	return cluster[center + y][center + x];
}

// distance from center of lattice
double rCenter(int x, int y) {
	double rSqd = x*x + y*y;
	return sqrt(rSqd);
}

// max distance of cluster sites from center
double rMax;

// add site and adjust rMax
void addSite(int x, int y) {
	int center = (L - 1) / 2;
	cluster[center + y][center + x] = true;
	double r = rCenter(x,y);
	if(r > rMax)
		rMax = r;
}

// cluster and lattice for n sites
void initialize(int n) {
	//choose lattice large enough for n sites
	//area of fractal disk
	double area = n;
	// under-estimate of fractal dimension
	double df = 1.6;
	// over-estimate of disc radius
	double r = pow(area / pi, 1 / df);
	// make L/2 50% larger than r
	L = int(3 * r);
	// make L odd
	if ( L % 2 == 0) ++L;
	cout << " Using " << L << " x " << L << " lattice " << endl;

	// create two dimensional cluster array and add site at origin
	vector< vector<bool> > empty(L, vector<bool>(L, false));
	cluster = empty;
	rMax = 0;
	addSite(0, 0);
}

// attempt to add a site using random walk
// return true if attempt succeeds
bool randomWalk() {
	int nStart = min(5, (L-1)/2);
	double rStart = rMax + nStart;
	double rStop = 1.5 * rStart;

	double theta = 2 * pi * ranf(seed);
	int x = int(rStart * cos(theta));
	int y = int(rStart * sin(theta));

	while (true) {

		// check wether walker is too far away
		double r = rCenter(x, y);
		if(r >= rStop)
			break;
		// check wether walker is adjacent to an occupied site
		if (onLattice(x, y) && !occupied(x, y) &&
				(occupied(x + 1, y) || occupied(x -1, y) ||
				 occupied(x, y + 1) || occupied(x, y - 1) ) )
		{
			addSite(x, y);
			return true
		}
		// set the step size
		int stride = 1;
		// more than 5 steps from cluster double step size
		if (r > rMax +5)
			stride = 2;
		// take a random step
		const int EAST = 0, NORTH = 1, WEST = 2, SOUTH = 3;
		switch( int(4 * ranf(seed))) {
			case EAST:
				x += stride;
				break
			case NORTH:
					y += stride;
					break;
			case WEST:
					x -= stride;
					break;
			case SOUTH: 
					y-= stride;
					break;
			default: 
					break;
		}
	}
	return false;
}

void writeCluster(string filename) {
	ofstream file(filename.c_str());
	int xyMax = (L - 1) / 2;
	for (int x = -xyMax; x <= xyMax; x++)
		for (int y = -xyMax; y <= xyMax; y++)
			if(occupied(x, y))
				file << x << '\t' << y << '\n';
	file.close();
}

int main() {

	cout << " Random Walk Simulation of Diffusion Limited Aggregation\n"
		<< " -------------------------------------------------------\n"
		<< " Enter number of particles to simulate: ";
	int n;
	cin >> n;

	// initialize random generator
	seed = timeSeed();
	// create lattice and add site at center
	initialize(n);
	// cluster has one occupied site
	int sites = 1;
	// count number of failed walks
	int failedWalks = 0;
	while(sites < n) {
		// walk succeeded
		if (randomWalk()) {
			++sites;
			if (sites % 10 == 0)
				cout << sites << " " << flush;
		}
		else
			++failedWalks;
	}
	cout << " Done\n Number of failed walks = " << failedWalks << endl;
	string name("dla.data");
	writeCluster(name);
	cout << " DLA cluster saved in file " << name << endl;
}
