#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cond1(std::vector<int> grid, const int n, int index);
bool cond2(std::vector<int> grid, const int n, int index);
bool cond3(std::vector<int> grid, const int n, int index, int k);
bool cond4(std::vector<int> grid, const int n, int index, int k);

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

	grid[0] = 2;
	for(iter = 0; iter < n; iter++)
	{
		for(jter = 0; jter < n; jter++)
		{
			index = iter*n+jter;
			if(index == 0)
				continue;
			if(cond1(grid, n, index) && cond2(grid, n, index))
			{
				grid[index] = k;
				k++;
			}
		}
	}
}

bool cond1(std::vector<int> grid, const int n, int index)
{
	return index - 1 < 0 || grid[index-1] == 0;
}

bool cond2(std::vector<int> grid, const int n, int index)
{
	return index - n < 0 || grid[index-n] == 0;
}

bool cond3(std::vector<int> grid, const int n, int index, int k)
{
	return grid[index - 1] < k;
}

bool cond4(std::vector<int> grid, const int n, int index, int k)
{
	return grid[index - n] < k;
}
