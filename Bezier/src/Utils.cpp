#include "../include/Utils.h"
#include <stdio.h>

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

int output_bezier_curve(FILE *fp, double q[HDIM])
{
	fprintf(fp, "%lf\t%lf\t%lf\t%lf\n", q[0], q[1], q[2], q[3]);
	return 0;
}

int ouputPltFile()
{
	FILE *outputfile;
	outputfile = fopen("plot_bezier.plt", "w");
	if (outputfile == NULL)
	{
		printf("cannnot open [plot_bezier.plt]\n");
		return -1;
	}
	fprintf(outputfile, "set view equal xyz\n");
	fprintf(outputfile, "set xlabel \"X-Axis\"\n");
	fprintf(outputfile, "set ylabel \"Y-Axis\"\n");
	fprintf(outputfile, "set zlabel \"Z-Axis\"\n");
	fprintf(outputfile, "set xrange [-5:5]\n");
	fprintf(outputfile, "set yrange [-5:5]\n");
	//fprintf(outputfile, "set zrange [0:5]\n");
	fprintf(outputfile, "set ticslevel 0\n");
	fprintf(outputfile, "set datafile separator \"\t\"\n");
	fprintf(outputfile, "splot for [IDX=0:100] \"../output/bezier_result.csv\" index IDX using 1:2:3 pt 7 ps 2 lc rgb \"black\" ");
	//fprintf(outputfile, ", \"coordinate_o.txt\" using 1:2:3 with lines lw 1.5 lc rgb \"black\" ");
	fprintf(outputfile, ", for [IDX=0:100] \"../resource/bezier_curve_control_points.csv\" index IDX using 2:3:4 pt 7 ps 3 lc rgb \"red\" \n");
	//fprintf(outputfile, ", for [IDX=0:100] \"../output/txt/coordinate_y.txt\" index IDX using 1:2:3 with lines lw 1.5 lc rgb \"green\"");
	//fprintf(outputfile, ", for [IDX=0:100] \"../output/txt/coordinate_z.txt\" index IDX using 1:2:3 with lines lw 1.5 lc rgb \"blue\" \n");
	fclose(outputfile);
	return 0;
}

int plot2gnuplot()
{
	ouputPltFile();
	system("wgnuplot -persist plot_bezier.plt");
	return 0;
}