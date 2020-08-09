#include "uniform.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

double unif() 
{
	return rand() / double(RAND_MAX);
}

double unif(double a, double b)
{
	return (b - a) * unif() + a;
}


long unif(long a)
{
	if (a < 0) a = -a;
	if (a == 0) return 0;
	return long(unif() * a) + 1;
}

void seed()
{
	srand(time(0));
}

double needle(double b)
{
	double x = unif(0, b / 2);
	return x;
}

double needle2()
{
	double pi = 3.1415926535897932384626;
	double phi = unif(0, pi/2);
	return phi;
}


double buffon(double l, double b, double Nsample)
{
	double Nhits = 0;
	for (int i = 0; i < Nsample; i++)
	{
		double x_tip = needle(b) - (l * cos(needle2()) / 2);
		if (x_tip < 0)
		{
			Nhits++; 
		}

	}
	return Nhits / Nsample;
}

int main()
{
	std::cout << "Numerical Result: " <<  buffon(1, 1, 100000000) << " \n" <<  "Analytical Result: " << 2/(3.1415 * 1) ;
}

