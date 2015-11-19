#include "../include/util.h"

void printVec(double u[])
{
	//printf("[");
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		printf("[ %2.1lf ]\n", u[i]);
	}
	//printf("]\n");
}

void printMat(double m[VECTOR_LEN][VECTOR_LEN])
{
	for (int i = 0; i < VECTOR_LEN; i++){
		printf("[");
		for (int j = 0; j < VECTOR_LEN; j++)
		{
			printf("\t%3.2lf", m[i][j]);
		}
		printf("]\n");
	}
	printf("\n");
}

int output_as_arrow(double points[ARROW_VERTEX][VECTOR_LEN])
{
	static int init = 0;
	if (init == 0)
	{
		FILE *outputfile;
		outputfile = fopen("../output/txt/vertex.txt", "w");
		if (outputfile == NULL)
		{
			printf("cannot open [vertex.txt]\n");
			return -1;
		}
		for (int i = 0; i < ARROW_VERTEX; i++)
		{
			fprintf(outputfile, "%lf %lf %lf\n", points[i][0], points[i][1], points[i][2]);
		}
		fclose(outputfile);
		init = 1;
		return 0;
	}
	else
	{
		FILE *outputfile;
		outputfile = fopen("../output/txt/vertex.txt", "a");
		if (outputfile == NULL)
		{
			printf("cannot open [vertex.txt]\n");
			return -1;
		}
		fprintf(outputfile, "\n\n");
		for (int i = 0; i < ARROW_VERTEX; i++)
		{
			fprintf(outputfile, "%lf %lf %lf\n", points[i][0], points[i][1], points[i][2]);
		}
		fclose(outputfile);
		init = 1;
		return 0;
	}
}

// [in] 1つの位置ベクトルと3つの方向ベクトル
int output_as_coordinate(double vector_o[VECTOR_LEN], 
		double vector_x[VECTOR_LEN],
		double vector_y[VECTOR_LEN],
		double vector_z[VECTOR_LEN])
{
	static int init = 0;
	if (init == 0)
	{
		FILE *outputfile_o;
		outputfile_o = fopen("../output/txt/coordinate_o.txt", "w");
		if (outputfile_o == NULL)
		{
			printf("cannot open [coordinate_o.txt]\n");
			return -1;
		}
		FILE *outputfile_x;
		outputfile_x = fopen("../output/txt/coordinate_x.txt", "w");
		if (outputfile_x == NULL)
		{
			printf("cannot open [coordinate_x.txt]\n");
			return -1;
		}
		FILE *outputfile_y;
		outputfile_y = fopen("../output/txt/coordinate_y.txt", "w");
		if (outputfile_y == NULL)
		{
			printf("cannot open [coordinate_y.txt]\n");
			return -1;
		}
		FILE *outputfile_z;
		outputfile_z = fopen("../output/txt/coordinate_z.txt", "w");
		if (outputfile_z == NULL)
		{
			printf("cannot open [coordinate_z.txt]\n");
			return -1;
		}
		fprintf(outputfile_o, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_x, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_x, "%lf %lf %lf\n", vector_o[0] + vector_x[0]/3, vector_o[1] + vector_x[1]/3, vector_o[2] + vector_x[2]/3);
		fprintf(outputfile_x, "\n\n");
		fprintf(outputfile_y, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_y, "%lf %lf %lf\n", vector_o[0] + vector_y[0]/3, vector_o[1] + vector_y[1]/3, vector_o[2] + vector_y[2]/3);
		fprintf(outputfile_y, "\n\n");
		fprintf(outputfile_z, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_z, "%lf %lf %lf\n", vector_o[0] + vector_z[0]/3, vector_o[1] + vector_z[1]/3, vector_o[2] + vector_z[2]/3);
		fprintf(outputfile_z, "\n\n");
		
		fclose(outputfile_o);
		fclose(outputfile_x);
		fclose(outputfile_y);
		fclose(outputfile_z);
		init = 1;
		return 0;
	}
	else
	{
		FILE *outputfile_o;
		outputfile_o = fopen("../output/txt/coordinate_o.txt", "a");
		if (outputfile_o == NULL)
		{
			printf("cannot open [coordinate_o.txt]\n");
			return -1;
		}
		FILE *outputfile_x;
		outputfile_x = fopen("../output/txt/coordinate_x.txt", "a");
		if (outputfile_x == NULL)
		{
			printf("cannot open [coordinate_x.txt]\n");
			return -1;
		}
		FILE *outputfile_y;
		outputfile_y = fopen("../output/txt/coordinate_y.txt", "a");
		if (outputfile_y == NULL)
		{
			printf("cannot open [coordinate_y.txt]\n");
			return -1;
		}
		FILE *outputfile_z;
		outputfile_z = fopen("../output/txt/coordinate_z.txt", "a");
		if (outputfile_z == NULL)
		{
			printf("cannot open [coordinate_z.txt]\n");
			return -1;
		}

		fprintf(outputfile_o, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_x, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_x, "%lf %lf %lf\n", vector_o[0] + vector_x[0]/3, vector_o[1] + vector_x[1]/3, vector_o[2] + vector_x[2]/3);
		fprintf(outputfile_x, "\n\n");
		fprintf(outputfile_y, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_y, "%lf %lf %lf\n", vector_o[0] + vector_y[0]/3, vector_o[1] + vector_y[1]/3, vector_o[2] + vector_y[2]/3);
		fprintf(outputfile_y, "\n\n");
		fprintf(outputfile_z, "%lf %lf %lf\n", vector_o[0], vector_o[1], vector_o[2]);
		fprintf(outputfile_z, "%lf %lf %lf\n", vector_o[0] + vector_z[0]/3, vector_o[1] + vector_z[1]/3, vector_o[2] + vector_z[2]/3);
		fprintf(outputfile_z, "\n\n");
		
		fclose(outputfile_o);
		fclose(outputfile_x);
		fclose(outputfile_y);
		fclose(outputfile_z);
		return 0;
	}
}

int resetOutputFile()
{
	FILE *outputfile;
	outputfile = fopen("../output/txt/vertex.txt", "w");
	if (outputfile == NULL)
	{
		printf("cannot open [vertex.txt]\n");
		return -1;
	}
	fclose(outputfile);

	FILE *coordinate_files[4];
	coordinate_files[0] = fopen("../output/txt/coordinate_o.txt", "w");
	coordinate_files[1] = fopen("../output/txt/coordinate_x.txt", "w");
	coordinate_files[2] = fopen("../output/txt/coordinate_y.txt", "w");
	coordinate_files[3] = fopen("../output/txt/coordinate_z.txt", "w");
	for (int i = 0; i < 4; i++)
	{
		if (coordinate_files[i] == NULL)
		{
			printf("cannot open [coordinate.txt]\n");
			return -1;
		}
		fclose(coordinate_files[i]);
	}
}

int ouputPltFile()
{
	FILE *outputfile;
	outputfile = fopen("plot_vertex.plt", "w");
	if (outputfile == NULL)
	{
		printf("cannnot open [plot_vertex.plt]\n");
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
	fprintf(outputfile, "splot for [IDX=0:100] \"../output/txt/vertex.txt\" index IDX using 1:2:3 with lines lw 2.0");
	//fprintf(outputfile, ", \"coordinate_o.txt\" using 1:2:3 with lines lw 1.5 lc rgb \"black\" ");
	fprintf(outputfile, ", for [IDX=0:100] \"../output/txt/coordinate_x.txt\" index IDX using 1:2:3 with lines lw 1.5 lc rgb \"red\"");
	fprintf(outputfile, ", for [IDX=0:100] \"../output/txt/coordinate_y.txt\" index IDX using 1:2:3 with lines lw 1.5 lc rgb \"green\"");
	fprintf(outputfile, ", for [IDX=0:100] \"../output/txt/coordinate_z.txt\" index IDX using 1:2:3 with lines lw 1.5 lc rgb \"blue\" \n");
	fclose(outputfile);
	return 0;
}

int plot2gnuplot()
{
	ouputPltFile();
	system("wgnuplot -persist plot_vertex.plt");
	return 0;
}