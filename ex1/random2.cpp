#include <iostream>
#include <fstream>
#include <random>
#include <math.h>
//#include <cmath>

int main()
{
	std::ofstream data;
	data.open ("data.txt");
	std::mt19937 gen(42);
	std::uniform_real_distribution<double> rdis(0,1);
	std::uniform_real_distribution<double> phidis(0,2*M_PI);
	double r, phi;
	double x, y;
	int n = 10000;
	for(int i=0; i<n; i++)
	{
		r = std::sqrt(rdis(gen));
		phi = phidis(gen);
		x = r*std::cos(phi);
		y = r*std::sin(phi);
		data << x << "\t" << y << std::endl;
	}
	data.close();
	return 0;
} 
