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

	const unsigned int n = 24;

	unsigned int ncircles = 0;
	double d = 0;
	std::vector<double> distance;
	double x,y,z = 0;

	const double sphere_radius = 0.2;
	bool touch = 0;
	unsigned int fail = 0;

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

			d = std::sqrt(x*x + y*y + z*z)-2*sphere_radius;
			if(d <= 0)
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
	for( std::vector<std::vector<double> >::iterator i = circles.begin(); i != circles.end(); ++i)
	{
		for( std::vector<std::vector<double> >::iterator j = circles.begin(); j != i; ++j)
		{
			x = (*i)[0]-(*j)[0];
			y = (*i)[1]-(*j)[1];
			z = (*i)[2]-(*j)[2];

			distance.push_back(std::sqrt(x*x + y*y + z*z));
		}
	}
	double distance_mean = std::accumulate(distance.begin(), distance.end(), 0.0)/double(distance.size());
	cout << "distance mean" << endl;
	cout << distance_mean << endl;

	cout << "coordinates" << endl;
	for( std::vector<std::vector<double> >::iterator it = circles.begin(); it != circles.end(); ++it)
	{
			cout << '(' << (*it)[0] << ',' << (*it)[1] << ',' << (*it)[2] << ')' << endl;
	}
	cout << "fails: " << fail << endl;
	return 0;
}
