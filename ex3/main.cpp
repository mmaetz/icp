#include <iostream>
#include <vector>
#include <random>
#include "functions.h"

using namespace std;


main () {
	int iter = 0;
	int jter = 0;
	const int n = 10;
	std::vector<int> grid(n*n);

	const int seed = 42;
	const double p = 0.6;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);
	for(iter = 0; iter < grid.size(); iter++)
	{
		if(dis(gen) < p)
			grid[iter] = 1;
	}
	std::vector<int> M(n*n);
	M[2] = 1;

	print(grid,n);
	hoshen_kopelman(grid, n, M);
	cout << "********************" << endl;
	print(grid,n);
	cout << endl;

	for(std::vector<int>::iterator it = M.begin(); it != M.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}
