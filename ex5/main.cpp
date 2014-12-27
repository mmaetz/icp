#include <iostream>
#include <vector>
#include <math.h>
#include <random>

using namespace std;

int main() {
	std::mt19937 gen(42);
	std::uniform_real_distribution<double> dis(0,1);

	std::vector<std::vector<double>> circles(0, std::vector<double>(3));
	std::vector<double> position(3);
	int n = 10;
	int ncircles = 0;
	double distance = 0;
	double x = 0;
	double y = 0;
	double z = 0;

	double sphere_radius = 0.2;
	bool touch = 0;
	int fail = 0;
	while(ncircles < n)
	{
		touch = 0;
		position[0] = dis(gen);
		position[1] = dis(gen);
		position[2] = dis(gen);

		for( std::vector<std::vector<double> >::iterator it = circles.begin(); it != circles.end(); ++it)
		{
			x = (*it)[0]-position[0];
			y = (*it)[1]-position[1];
			z = (*it)[2]-position[2];

			distance = std::sqrt(x*x + y*y + z*z)-2*sphere_radius;
			if(distance < 0)
			{
				touch = 1;
				fail++;
				break;
			}
		}
		if(touch == 0)
		{
			circles.push_back(position);
			ncircles++;
		}
	}
	cout << "coordinates" << endl;
	for( std::vector<std::vector<double> >::iterator it = circles.begin(); it != circles.end(); ++it)
	{
			cout << '(' << (*it)[0] << ',' << (*it)[1] << (*it)[2] << ')' << endl;
	}
	cout << "fails: " << fail << endl;
	return 0;
}
