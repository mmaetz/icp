#include "burner.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main ()
{
	double p = 0.6;
	int timesteps = 0;
	bool reach = 0;

	std::vector<int> timesteps_vec;
	std::vector<bool> reach_vec;

	std::vector<double> timesteps_avg;
	std::vector<double> reach_avg;

	int measurements = 1000;

	for(double p=0.587; p<0.597; p+=0.001)
	{
		for(int seed=0; seed < measurements; seed++)
		{
			timesteps = 0;
			reach = 0;
			burner(p, seed, timesteps, reach);
			timesteps_vec.push_back(double(timesteps));
			reach_vec.push_back(double(reach));
		}
		cout << "p: " << p << endl;
		cout << "timesteps: " << double(std::accumulate(timesteps_vec.begin(), timesteps_vec.end(), 0))/double(measurements) << endl;
		cout << "reach: " << double(std::accumulate(reach_vec.begin(), reach_vec.end(), 0))/double(measurements) << endl;
//		timesteps_avg.push_back(std::accumulate(timesteps_vec.begin(), timesteps_vec.end(), 0)/measurements);
//		reach_avg.push_back(std::accumulate(reach_vec.begin(), reach_vec.end(), 0)/measurements);
		timesteps_vec.clear();
		reach_vec.clear();
	}
	return 0;
}
