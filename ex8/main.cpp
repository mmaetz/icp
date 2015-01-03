#include <iostream>
#include <cmath>

double func(double x, double x0);
double deriv(double x, double x0);
double dderiv(double x, double x0);

main () {
	double x0 = 1;
//	y0 = 1;
//
	double x = 50;
	std::cout << x << std::endl;
	while(std::abs(deriv(x,x0))>1e-8)
	{
		x = x-deriv(x,x0)/dderiv(x,x0);
		std::cout << x << std::endl;
	}
	std::cout << std::abs(deriv(x,x0)) << std::endl;
}

double func(double x, double x0)
{
	return exp(-(x-x0)*(x-x0));
}

double deriv(double x, double x0)
{
	return -2*(x-x0)*exp(-(x-x0)*(x-x0));
}

double dderiv(double x, double x0)
{
	return (-2+4*(x-x0)*(x-x0))*exp(-(x-x0)*(x-x0));
}
