#include <iostream>
#include <vector>
#include <random>

using namespace std;

main () {
	int iter = 0;
	int jter = 0;
	const int n = 10;
	std::vector<int> grid(n*n);
	std::vector<int> M(1);
	M.push_back(1);
	int k=2;

	const int seed = 42;
	const double p = 0.5;

	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> dis(0,1);
	for(iter = 0; iter < grid.size(); iter++)
	{
		if(dis(gen) < p)
			grid[iter] = 1;
	}

	for(iter = 0; iter < n; iter++)
	{
		for(jter = 0; jter < n; jter++)
		{
			cout << grid[jter*n+iter] << " " ;
		}
		cout << endl;
	}
}
