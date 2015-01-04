#include <iostream>
#include <cmath>

double func(double x, double x0, double y, double y0);
double xderiv(double x, double x0, double y, double y0);
double yderiv(double x, double x0, double y, double y0);
double xxderiv(double x, double x0, double y, double y0);
double yyderiv(double x, double x0, double y, double y0);
double xyderiv(double x, double x0, double y, double y0);

main () {
	double x0 = 1;
//	y0 = 1;
//
	double x = 50;
	std::cout << "x = " << x << std::endl;
	while(std::abs(deriv(x,x0))>1e-8)
	{
		x = x-deriv(x,x0)/dderiv(x,x0);
		std::cout << "x = " << x << std::endl;
	}
	std::cout << std::abs(deriv(x,x0)) << std::endl;
}

double func(double x, double x0)
{
	return exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double xderiv(double x, double x0, double y, double y0)
{
	return -2*(x-x0)*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double yderiv(double x, double x0, double y, double y0)
{
	return -2*(y-y0)*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double xxderiv(double x, double x0, double y, double y0)
{
	return (-2+4*(x-x0)*(x-x0))*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double yyderiv(double x, double x0, double y, double y0)
{
	return (-2+4*(y-y0)*(y-y0))*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double xyderiv(double x, double x0, double y, double y0)
{
	return 4*(x-x0)*(y-y0)*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double xxderiv(double x, double x0, double y, double y0)
{
	return (-2+4*(x-x0)*(x-x0))*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double yyderiv(double x, double x0, double y, double y0)
{
	return (-2+4*(y-y0)*(y-y0))*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}

double xyderiv(double x, double x0, double y, double y0)
{
	return 4*(x-x0)*(y-y0)*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}
