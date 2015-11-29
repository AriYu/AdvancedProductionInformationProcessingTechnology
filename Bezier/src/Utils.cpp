#include "../include/Utils.h"
#include <stdio.h>
#include <string.h>

int read_2d_control_pointslist_from_file(char filename[], double control_pointslist[BDIM + 1][HDIM])
{
	FILE *fp;
	int ret = 0;
	double x, y, z = 0.0;
	int index = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("%sファイルが開けません．\n", filename);
		return -1;
	}
	while ((ret = fscanf(fp, "%d\t%lf\t%lf\t%lf", &index, &x, &y, &z)) != EOF)
	{
		control_pointslist[index][0] = x;
		control_pointslist[index][1] = y;
		control_pointslist[index][2] = z;
		control_pointslist[index][3] = 0;
	}
	return 0;
}

int read_3d_control_pointslist_from_file(char filename[], double control_pointslist[BDIM + 1][BDIM+1][HDIM])
{
	FILE *fp;
	int ret = 0;
	double x, y, z = 0.0;
	int index_u, index_v = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("%sファイルが開けません．\n", filename);
		return -1;
	}
	while ((ret = fscanf(fp, "%d\t%d\t%lf\t%lf\t%lf", &index_u, &index_v, &x, &y, &z)) != EOF)
	{
		control_pointslist[index_u][index_v][0] = x;
		control_pointslist[index_u][index_v][1] = y;
		control_pointslist[index_u][index_v][2] = z;
		control_pointslist[index_u][index_v][3] = 0;
	}
	return 0;
}


int output_bezier_curve(FILE *fp, double q[HDIM])
{
	fprintf(fp, "%lf\t%lf\t%lf\t%lf\n", q[0], q[1], q[2], q[3]);
	return 0;
}

int ouputPltFile(char filename[])
{
	FILE *outputfile;
	outputfile = fopen("plot_bezier.plt", "w");
	if (outputfile == NULL)
	{
		printf("cannnot open [plot_bezier.plt]\n");
		return -1;
	}
	fprintf(outputfile, "reset\n");
	fprintf(outputfile, "set view equal xyz\n");
	fprintf(outputfile, "set xlabel \"X-Axis\"\n");
	fprintf(outputfile, "set ylabel \"Y-Axis\"\n");
	fprintf(outputfile, "set zlabel \"Z-Axis\"\n");
	//fprintf(outputfile, "set xrange [-1:10]\n");
	//fprintf(outputfile, "set yrange [-1:10]\n");
	//fprintf(outputfile, "set zrange [0:5]\n");
	fprintf(outputfile, "set ticslevel 0\n");
	fprintf(outputfile, "set datafile separator \"\t\"\n");
	//fprintf(outputfile, "set cbrange[-1.5:1.5]\n");
	fprintf(outputfile, "splot for [IDX=0:1000] \"%s\" index IDX using 1:2:3 with linespoints lc rgb \"blue\" pt 7,", "../output/bezier_curve.csv");
	fprintf(outputfile, "for [IDX=0:1000] \"%s\" index IDX using 1:2:3 with linespoints lc rgb \"red\" pt 4", "../output/bezier_surface.csv");
	//fprintf(outputfile, "splot for [IDX=0:1000] \"%s\" index IDX using 1:2:3 with linespoints lc rgb \"black\"", "../output/bezier_surface.csv");
	fprintf(outputfile, "\n");
	//fprintf(outputfile, ", for [IDX=0:1000] \"../resource/bezier_curved_surface_control_points.csv\" index IDX using 3:4:5 pt 7 ps 2 lc rgb \"red\" \n");
	fclose(outputfile);
	return 0;
}

int plot2gnuplot(char filename[])
{
	ouputPltFile(filename);
	char command[100] = "gnuplot -persist plot_bezier.plt";
	system(command);
	return 0;
}

void printVec(double u[])
{
	//printf("[");
	for (int i = 0; i < HDIM; i++)
	{
		printf("[ %2.1lf ]\n", u[i]);
	}
	//printf("]\n");
}

void printMat(double m[HDIM][HDIM])
{
	for (int i = 0; i < HDIM; i++){
		printf("[");
		for (int j = 0; j < HDIM; j++)
		{
			printf("\t%3.2lf", m[i][j]);
		}
		printf("]\n");
	}
	printf("\n");
}