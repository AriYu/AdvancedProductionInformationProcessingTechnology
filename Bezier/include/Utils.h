#ifndef UTILS_H_
#define UTILS_H_
#define _CRT_SECURE_NO_DEPRECATE
#include "Kadai3.h"
#include <stdio.h>
#include <stdlib.h>

int read_2d_control_pointslist_from_file(char filename[], double control_pointslist[BDIM + 1][HDIM]);
int read_3d_control_pointslist_from_file(char filename[], double control_pointslist[BDIM + 1][BDIM + 1][HDIM]);
int output_bezier_curve(FILE *fp, double q[HDIM]);
int plot2gnuplot(char filename[]);
void printVec(double u[]);
void printMat(double m[HDIM][HDIM]);

#endif