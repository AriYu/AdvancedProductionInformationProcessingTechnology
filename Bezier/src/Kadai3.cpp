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
		printf("%s�t�@�C�����J���܂���D\n", output_file);
		return -1;
	}

	for (double i = 0; i < 1.0 + (1.0 / 20.0); i += (1.0 / 20.0))
	{
		on_bezier3_curve(q, M_B, control_pointslist, i);
		printf("q : [%lf] %lf, %lf, %lf, %lf\n",i, q[0], q[1], q[2], q[3]);
		output_bezier_curve(fp, q);
	}
	plot2gnuplot(output_file);
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
	char output_file_surface[] = "../output/bezier_surface.csv";
	FILE *fp_surface;
	fp_surface = fopen(output_file_surface, "w");
	if (fp_surface == NULL)
	{
		printf("%s�t�@�C�����J���܂���D\n", output_file_surface);
		return -1;
	}
	char output_file_curve[] = "../output/bezier_curve.csv";
	FILE *fp_curve;
	fp_curve = fopen(output_file_curve, "w");
	if (fp_curve == NULL)
	{
		printf("%s�t�@�C�����J���܂���D\n", output_file_curve);
		return -1;
	}
	char output_file_curve_and_surface[] = "../output/bezier_curve_and_surface.csv";
	FILE *fp_curve_and_surface;
	fp_curve_and_surface = fopen(output_file_curve_and_surface, "w");
	if (fp_curve_and_surface == NULL)
	{
		printf("%s�t�@�C�����J���܂���D\n", output_file_curve_and_surface);
		return -1;
	}
	for (double u = 0; u <= 1.0 + 1.0/20.0; u += (1.0 / 20.0))
	{
		for (double v = 0; v <= 1.0 + 1.0/20.0; v += (1.0 / 20.0))
		{
			on_bezier3_surface(q, M_B, control_pointslist, u, v);
			printf("[%lf][%lf] : %lf, %lf, %lf, %lf\n", u, v, q[0], q[1], q[2], q[3]);
			output_bezier_curve(fp_surface, q);
			output_bezier_curve(fp_curve_and_surface, q);
		}
		fprintf(fp_surface, "\n\n");
		fprintf(fp_curve_and_surface, "\n\n");
	}

	for (int i = 0; i < 4; i++)
	{
		for (double j = 0; j < 1.0 + 1.0/20.0; j += (1.0 / 20.0))
		{
			on_bezier3_curve(q, M_B, control_pointslist[i], j);
			printf("q : [%lf] %lf, %lf, %lf, %lf\n", j, q[0], q[1], q[2], q[3]);
			output_bezier_curve(fp_curve, q);
			output_bezier_curve(fp_curve_and_surface, q);
		}
		fprintf(fp_curve, "\n\n");
		fprintf(fp_curve_and_surface, "\n\n");
	}
	//plot2gnuplot(output_file_surface);
	//plot2gnuplot(output_file_curve);
	plot2gnuplot(output_file_curve_and_surface);
	return 0;
}
