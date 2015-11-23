#include "../include/Bezier.h"
#include "../include/base_vector.h"
#include <math.h>

void set_param_vector(double pv[BDIM + 1], double t)
{
	for (int i = 0; i < BDIM + 1; i++)
	{
		pv[i] = pow(t, i);
	}
}

void mulMVb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1])
{
	double u_tmp[BDIM + 1];
	for (int i = 0; i < BDIM + 1; i++)
	{
		u_tmp[i] = 0;
		for (int j = 0; j < BDIM + 1; j++)
		{
			u_tmp[i] += (mb[i][j] * v[j]);
		}
		u[i] = u_tmp[i];
	}
}

void scaleVec4b(double u[], double k, double v[])
{
	for (int i = 0; i < HDIM; i++)
	{
		u[i] = k * v[i];
	}
}

void mulLCpVb(double u[HDIM], double cps[BDIM + 1][HDIM], double v[BDIM + 1])
{
	double cps_tmp[BDIM + 1][HDIM];
	for (int i = 0; i < BDIM + 1; i++)
	{
		printf("cps[%d] : %lf, %lf, %lf, %lf\n", i, cps[i][0], cps[i][1], cps[i][2], cps[i][3]);
		printf("v[%d] : %lf\n", i, v[i]);
		scaleVec4b(cps_tmp[i], v[i], cps[i]);
		printf("cps_tmp[%d] : %lf, %lf, %lf, %lf\n", i, cps_tmp[i][0], cps_tmp[i][1], cps_tmp[i][2], cps_tmp[i][3]);
		add4h(u, u, cps_tmp[i]);
		printf("u : %lf, %lf, %lf, %lf\n\n", u[0], u[1], u[2], u[3]);
	}
}

void on_bezier3_curve(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][HDIM], double t)
{
	double tn[BDIM + 1];
	double Mt[BDIM + 1];
	// q‚Ì‰Šú‰»
	for (int i = 0; i < HDIM; i++)
	{
		q[i] = 0.0;
	}

	// t^n ‚ÌŒvŽZ
	set_param_vector(tn, t);

	// Mt = M * t^n ‚ÌŒvŽZ
	mulMVb(Mt, mb, tn);

	// q = cps * Mt ‚ÌŒvŽZ
	mulLCpVb(q, cps, Mt);
}