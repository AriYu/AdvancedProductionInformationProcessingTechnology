#include "../include/Bezier.h"
#include "../include/base_vector.h"
#include "../include/Utils.h"
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

void mulVMb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1])
{
	double u_tmp;
	for (int i = 0; i < BDIM + 1; i++)
	{
		u_tmp = 0;
		for (int j = 0; j < BDIM + 1; j++)
		{
			u_tmp += (mb[j][i] * v[j]);
		}
		u[i] = u_tmp;
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
		scaleVec4b(cps_tmp[i], v[i], cps[i]);
		add4h(u, u, cps_tmp[i]);
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

void mulPMb(double mcp[BDIM + 1][BDIM + 1][HDIM], double p[BDIM + 1][BDIM + 1][HDIM], double Mb[BDIM + 1][BDIM +1])
{
	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < BDIM + 1; j++)
		{
			for (int k = 0; k < HDIM - 1; k++)
			{
				mcp[i][j][k] += p[i][j][k] * Mb[j][i];
			}
		}
	}
}

void mulMCpVb(double lcp[BDIM + 1][HDIM], double mcp[BDIM + 1][BDIM + 1][HDIM], double v[BDIM + 1])
{
	for (int i = 0; i < BDIM + 1; i++)
	{
		double cps_tmp[HDIM];
		for (int j = 0; j < BDIM + 1; j++)
		{
			scaleVec4b(cps_tmp, v[j], mcp[i][j]);
			add4h(lcp[i], lcp[i], cps_tmp);
		}
	}
}

void transposition4b(double mT[BDIM + 1][BDIM + 1], double m[BDIM + 1][BDIM + 1])
{
	double tmp[BDIM + 1][BDIM + 1];
	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < BDIM + 1; j++)
		{
			tmp[i][j] = m[j][i];
		}
	}
	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < BDIM + 1; j++)
		{
			mT[i][j] = tmp[i][j];
		}
	}
}

void on_bezier3_surface(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][BDIM + 1][HDIM], double u, double v)
{
	double un[BDIM + 1];
	double vn[BDIM + 1];
	set_param_vector(un, u);
	set_param_vector(vn, v);

	// q‚Ì‰Šú‰»
	for (int i = 0; i < HDIM; i++)
	{
		q[i] = 0.0;
	}
	// PMb = P * Mb
	double PMb[BDIM + 1][BDIM + 1][HDIM];
	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < BDIM + 1; j++)
		{
			for (int k = 0; k < HDIM; k++)
			{
				PMb[i][j][k] = 0.0;
			}
		}
	}
	mulPMb(PMb, cps, mb);
	// PMv = PMb * v^n
	double PMv[BDIM + 1][HDIM];
	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < HDIM; j++)
		{
			PMv[i][j] = 0.0;
		}
	}
	mulMCpVb(PMv, PMb, vn);
	printf("PMv : \n");
	printMat(PMv);

	// uM = u^n * Mb^T
	double uM[BDIM + 1];
	// tmb = Mb^T
	double tmb[BDIM + 1][BDIM + 1];
	// mb‚Ì“]’u‚ð‹‚ß‚é
	transposition4b(tmb, mb);
	// uM = u^n * Mb^T ‚ðŒvŽZ
	mulVMb(uM, tmb, un);

	for (int i = 0; i < BDIM + 1; i++)
	{
		for (int j = 0; j < HDIM - 1; j++)
		{
			q[j] += uM[i] * PMv[i][j];
		}
	}
}