#ifndef UTIL_H_
#define UTIL_H_

#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include "base_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARROW_VERTEX 8

void printVec(double u[]);
void printMat(double m[VECTOR_LEN][VECTOR_LEN]);
int output_as_arrow(double points[ARROW_VERTEX][VECTOR_LEN]);
int output_as_coordinate(double vector_o[VECTOR_LEN],double vector_x[VECTOR_LEN], double vector_y[VECTOR_LEN], double vector_z[VECTOR_LEN]);
int resetOutputFile();
int plot2gnuplot();
#endif