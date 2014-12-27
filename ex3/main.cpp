#include <iostream>
#include <vector>
#include <random>

using namespace std;

void print(std::vector<int> grid,  const int n);
void hoshen_kopelman(std::vector<int>& grid, const int n);
bool cond1(std::vector<int> grid, const int n, int index);
bool cond2(std::vector<int> grid, const int n, int index);
bool cond3(std::vector<int> grid, const int n, int index, int k);
bool cond4(std::vector<int> grid, const int n, int index, int k);

main () {
	int iter = 0;
	int jter = 0;
	const int n = 10;
	std::vector<int> grid(n*n);

	const int seed = 42;
	const double p = 0.5;
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);
	for(iter = 0; iter < grid.size(); iter++)
	{
		if(dis(gen) < p)
			grid[iter] = 1;
	}
//	print(grid, n);
	hoshen_kopelman(grid, n);
}
