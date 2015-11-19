#include "../include/random_gen.h"

void renew_seed(void)
{
	time_t ltime;
	time(&ltime);
	srand((unsigned int)ltime);
}

double random_in_range(double rmin, double rmax)
{
	double num = (double)rand() / RAND_MAX;
	return num*(rmax - rmin) + rmin;
}