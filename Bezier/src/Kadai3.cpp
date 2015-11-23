#include "../include/Kadai3.h"
#include "../include/Utils.h"

int kadai3_1()
{
	double M_B[BDIM + 1][BDIM + 1] = 
	{ 
		{ 1, -3, 3, -1 },
		{ 0, 3, -6, 3 },
		{ 0, 0, 3, -3 },
		{ 0, 0, 0, 1 }
	};
	double q[HDIM] = { 0, 0, 0, 0 };
	double control_pointslist[BDIM + 1][HDIM];
	char control_points_file[] = "../resource/bezier_curve_control_points.csv";
	if (read_2d_control_pointslist_from_file(control_points_file, control_pointslist))
	{
		return -1;
	}

	char output_file[] = "../output/bezier_result.csv";
	FILE *fp;
	fp = fopen(output_file, "w");
	if (fp == NULL)
	{
		printf("%sファイルが開けません．\n", output_file);
		return -1;
	}

	for (double i = 0; i < 1.0; i += (1.0 / 20.0))
	{
		on_bezier3_curve(q, M_B, control_pointslist, i);
		printf("q : [%lf] %lf, %lf, %lf, %lf\n",i, q[0], q[1], q[2], q[3]);
		output_bezier_curve(fp, q);
	}
	plot2gnuplot();
	return 0;
}

int kadai3_2()
{
	double M_B[BDIM + 1][BDIM + 1] =
	{
		{ 1, -3, 3, -1 },
		{ 0, 3, -6, 3 },
		{ 0, 0, 3, -3 },
		{ 0, 0, 0, 1 }
	};
	double q[HDIM] = { 0, 0, 0, 0 };
	double control_pointslist[BDIM + 1][BDIM + 1][HDIM];
	char control_points_file[] = "../resource/bezier_curved_surface_control_points.csv";
	if (read_3d_control_pointslist_from_file(control_points_file, control_pointslist))
	{
		return -1;
	}

	char output_file[] = "../output/bezier_result.csv";
	FILE *fp;
	fp = fopen(output_file, "w");
	if (fp == NULL)
	{
		printf("%sファイルが開けません．\n", output_file);
		return -1;
	}

	for (double u = 0; u < 1.0; u += (1.0 / 20.0))
	{
		for (double v = 0; v < 1.0; v += (1.0 / 20.0))
		{
			on_bezier3_surface(q, M_B, control_pointslist, u, v);
			printf("[%lf][%lf] : %lf, %lf, %lf, %lf\n", u, v, q[0], q[1], q[2], q[3]);
			output_bezier_curve(fp, q);
		}
	}
	plot2gnuplot();
	return 0;
}
