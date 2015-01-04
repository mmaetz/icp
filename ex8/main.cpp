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
	double y0 = 1;
	double y = 1;
//	y0 = 1;
//
	double x = 1.1;
	std::cout << "x = " << x << std::endl;
	while(std::abs(xderiv(x, x0, y, y0))>1e-8)
	{
		x = x-xderiv(x,x0,y,y0)/xxderiv(x,x0, y, y0);
		std::cout << "x = " << x << std::endl;
	}
	std::cout << std::abs(xderiv(x, x0, y, y0)) << std::endl;
}

double func(double x, double x0, double y, double y0)
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

ouble xyderiv(double x, double x0, double y, double y0)
{
	return 4*(x-x0)*(y-y0)*exp(-(x-x0)*(x-x0)+(y-y0)*(y-y0));
}
