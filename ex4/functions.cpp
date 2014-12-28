#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

void hoshen_kopelman(std::vector<int>& grid, const int n, std::vector<int>& M)
{
	int k=2;

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
			{
				continue;
			}
			else
			if(index > 0)
				k1 = grid[index - 1];
			if(index >= n)
			{
				k2 = grid[index - n];
			}

			if(left_empty(grid, n, index) && up_empty(grid, n, index))
			{
				grid[index] = k;
				M[k] = 1;
				k++;
				continue;
			}
			if( left_empty(grid, n, index) && up_occ(grid, n, index, k) )
			{
				grid[index] = k2;
				M[k2]++;
				continue;
			}
			if( up_empty(grid, n, index) && left_occ(grid, n, index, k) )
			{
				grid[index] = k1;
				M[k1]++;
				continue;
			}
			if( left_occ(grid, n, index, k) && up_occ(grid, n, index, k) )
			{
				if( k1 == k2 )
				{
					grid[index] = k1;
					M[k1]++;
				}
				else
				{
					grid[index] = k1;
					M[k1] = M[k1] + M[k2] + 1;
					M[k2] = -k1;
				}
			}
		}
	}
	int mj = 0;
	bool change = 0;
	for(int mi = 0; mi<n*n; mi++)
	{
		mj = mi;
		change = 0;
		while(M[mj]<0)
		{
			mj = -M[mj];
			change = 1;
		}
		if(change == 1)
		{
			for(iter = 0; iter < n; iter++)
			{
				for(jter = 0; jter < n; jter++)
				{
					index = iter*n+jter;
					if(grid[index] == mi)
						grid[index] = mj;
				}
			}
		}
	}
	std::vector<int> ns(k);
	for(int kit = 0; kit < k; kit++)
	{
		if(M[kit]>0)
			ns[M[kit]]++;
	}
}

void biggest_cluster(std::vector<int>& grid, const int n, std::vector<int>& M)
{
	int iter = 0;
	int jter = 0;
	int index = 0;

	int M_max_el = *std::max_element(M.begin(), M.end());
	int M_max_index = 0;
	while(M[M_max_index] != M_max_el)
	{
		M_max_index++;
	}
	for(iter = 0; iter < n; iter++)
	{
		for(jter = 0; jter < n; jter++)
		{
			index = iter*n+jter;
			if(grid[index] == M_max_index)
				grid[index] = 1;
			else
				grid[index] = 0;
		}
	}
}


bool left_empty(std::vector<int> grid, const int n, int index)
{
	return index % n == 0 || grid[index-1] == 0;
}

bool up_empty(std::vector<int> grid, const int n, int index)
{
	return index - n < 0 || grid[index-n] == 0;
}

bool left_occ(std::vector<int> grid, const int n, int index, int k)
{
	return 0 < grid[index - 1];
}

bool up_occ(std::vector<int> grid, const int n, int index, int k)
{
	return 0 < grid[index - n];
}
