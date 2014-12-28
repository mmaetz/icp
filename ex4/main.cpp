#include <iostream>
#include <vector>
#include <random>
#include "functions.h"

using namespace std;


main () {
	int iter = 0;
	int jter = 0;
	int index = 0;
	const int n = 5;
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
	cout << endl;
	biggest_cluster(grid, n, M);
	print(grid,n);

//	for(std::vector<int>::iterator it = M.begin(); it != M.end(); it++)
//	{
//		cout << *it << ' ';
//	}
	cout << endl;
	const int mid = n/2;
	int mass_tmp = 0;
	std::vector<int> fdim;
	int offset = 0;
	for(offset = 0; offset < mid+1; offset++)
	{
		mass_tmp = 0;
		for(iter = mid-offset; iter <= mid+offset; iter++)
		{
			for(jter = mid-offset; jter <= mid+offset; jter++)
			{
				index = iter*n+jter;
				if(grid[index] == 1)
					mass_tmp++;
			}
		}
		fdim.push_back(mass_tmp);
	}
	for(std::vector<int>::iterator it = fdim.begin(); it != fdim.end(); it++)
	{
		cout << *it << ' ';
	}
}
