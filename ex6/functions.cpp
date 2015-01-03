#include <iostream>
#include <cmath>
#include <vector>
#include "functions.h"

using namespace std;

void initialize(int n, vector< vector<bool> >& cluster) {

	const double pi = 4 * atan(1.0);

	//choose lattice large enough for n sites
	//area of fractal disk
	double area = n;
	// under-estimate of fractal dimension
	double df = 1.6;
	// over-estimate of disc radius
	double r = pow(area / pi, 1 / df);
	// make L/2 50% larger than r
	int L = int(3 * r);
	// make L odd
	if ( L % 2 == 0) ++L;
	cout << " Using " << L << " x " << L << " lattice " << endl;

	// create two dimensional cluster array and add site at origin
	vector< vector<bool> > empty(L, vector<bool>(L, false));
	cluster = empty;
	int rMax = 0;
	addSite(0, 0, L, cluster, rMax);
}

void addSite(int x, int y, int L, vector< vector<bool> > cluster, int& rMax) {
	int center = (L - 1) / 2;
	cluster[center + y][center + x] = true;
	double r = rCenter(x,y);
	if(r > rMax)
		rMax = r;
}

double rCenter(int x, int y) {
	double rSqd = x*x + y*y;
	return sqrt(rSqd);
}
