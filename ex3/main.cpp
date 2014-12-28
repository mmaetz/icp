#include <iostream>
#include <vector>
#include <random>
#include "functions.h"

using namespace std;

void print(std::vector<int> grid,  const int n);
void hoshen_kopelman(std::vector<int>& grid, const int n);

main () {
	int iter = 0;
	int jter = 0;
	const int n = 4;
	std::vector<int> grid(n*n);

	const int seed = 42;
	const double p = 0.7;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);
	for(iter = 0; iter < grid.size(); iter++)
	{
		if(dis(gen) < p)
			grid[iter] = 1;
	}
//	print(grid, n);
//	print(grid,n);
	hoshen_kopelman(grid, n);
	cout << "********************" << endl;
	print(grid,n);
}
