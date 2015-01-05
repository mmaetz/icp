#include <iostream>
#include <vector>
#include <random>
#include <math.h>

main () {
	std::vector<double> pos(2);
	std::vector<double> pos_square;

	int seed = 42;
	unsigned long long int measurements = pow(10, 3);
	unsigned long long int steps = pow(10, 2);
	double r = 1;

	std::uniform_real_distribution<double> angle(0,2*M_PI);
	std::mt19937 gen(seed);

	double angle_it = 0;

	for(int k = 0; k < measurements; k++)
	{
		pos[0] = 0;
		pos[1] = 0;
		for(int i = 0; i < steps; i++)
		{
			angle_it = angle(gen);
			pos[0] = pos[0]+r*cos(angle_it);
			pos[1] = pos[1]+r*sin(angle_it);
		}
		pos_square.push_back(pos[0]*pos[0]+pos[1]*pos[1]);

//		std::cout << xpos_log[m] << ", " << ypos_log[m] << std::endl;
	}
	double distance_sum = std::accumulate(pos_square.begin(), pos_square.end(), 0.0);
	double distance_pow4 = 0;
	for(std::vector<double>::iterator it = pos_square.begin(); it != pos_square.end(); it++)
	{
		distance_pow4 += (*it)*(*it);
	}
	double error = (distance_pow4-distance_sum*distance_sum)/double(measurements);

	std::cout << "distance: " << distance_sum/measurements << std::endl;
	std::cout << "distance square: " << (distance_sum*distance_sum)/measurements << std::endl;
	std::cout << "distance pow4: " << distance_pow4/measurements << std::endl;
	std::cout << "error: " << error << std::endl;

}
