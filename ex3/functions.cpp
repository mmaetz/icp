#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

void print(std::vector<int> grid, const int n)
{
	int iter = 0;
	int jter = 0;
	int index = 0;

	for(iter = 0; iter < n; iter++)
	{
		for(jter = 0; jter < n; jter++)
		{
			index = iter*n+jter;
			std::string append = "  ";
			if((index+1) % n == 0)
				append = "\n\n";
			if(grid[index] < 10)
					cout << ' ' << grid[index] << append ;
			else
					cout << grid[index] << append ;
		}
	}
}

void hoshen_kopelman(std::vector<int>& grid, const int n)
{
	std::vector<int> M(n*n);
	int k=2;
	M[k] = 1;

	int iter = 0;
	int jter = 0;
	int index = 0;

	int k1 = 0;
	int k2 = 0;

	for(iter = 0; iter < n; iter++)
	{
		for(jter = 0; jter < n; jter++)
		{
			index = iter*n+jter;
			if(grid[index] == 0)
				continue;
			else
			if(index > 0)
				k1 = grid[index - 1];
			if(index >= n)
				k2 = grid[index - n];
			if(left_empty(grid, n, index) && up_empty(grid, n, index))
			{
				grid[index] = k;
				M[k] = 1;
				k++;
				cout << "a" << endl;
				cout << k << endl;
			}
			if( left_empty(grid, n, index) && up_occ(grid, n, index, k) )
			{
				grid[index] = k1;
				M[k1]++;
				cout << "b" << endl;
				cout << k << endl;
			}
			if( up_empty(grid, n, index) && left_occ(grid, n, index, k) )
			{
				grid[index] = k2;
				M[k2]++;
				cout << "c" << endl;
			}
			if( left_occ(grid, n, index, k) && up_occ(grid, n, index, k) )
			{
				if( k1 == k2 )
				{
					grid[index] = k1;
					M[k1]++;
					cout << "d" << endl;
				}
				if( k1 != k2 )
				{
					grid[index] = k1;
					M[k1] = M[k1] + M[k2] + 1;
					M[k2] = -k1;
					cout << "e" << endl;
				}
			}
			cout << "********************" << endl;
			print(grid,n);
		}
	}
}

bool left_empty(std::vector<int> grid, const int n, int index)
{
	return index % n || grid[index-1] == 0;
}

bool up_empty(std::vector<int> grid, const int n, int index)
{
	return index - n < 0 || grid[index-n] == 0;
}

bool left_occ(std::vector<int> grid, const int n, int index, int k)
{
	return 1 < grid[index - 1];
}

bool up_occ(std::vector<int> grid, const int n, int index, int k)
{
	return 1 < grid[index - n];
}
