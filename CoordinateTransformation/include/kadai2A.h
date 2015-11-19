#ifndef KADAI_2A_H_
#define KADAI_2A_H_
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "base_vector.h"
#include "kadai1B.h"

#define TETRA_V_NUM 4
#define TRIPRISM_V_NUM 6
#define DIM 4

void set_tetra(double vs[][DIM]);

void set_triprism(double vs[][DIM], double h);

void norm_triangle(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM]);

void prStlProlog(char *label);

void prStlEpilog(char *label);

void prStlFacet(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM]);

void prStlTetra(double vs[][DIM], char *label);

void prStlTriprism(double vs[][DIM], char *label);

void prStlProlog2file(char *label, FILE *outputfile);

void prStlEpilog2file(char *label, FILE *outputfile);

void prStlFacet2file(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM], FILE *outputfile);

void prStlTetra2file(double vs[][DIM], char *label, FILE *outputfile);

void prStlTriprism2file(double vs[][DIM], char *label, FILE *outputfile);
/* --------------------
上記補助関数の利用例．
各立体の頂点データは座標変換などにも使うため，
頂点データの入れ物＝配列は，この関数の外で宣言する．
tt (O)：４面体の頂点を格納する配列．
tp (O)：３角柱の頂点を格納する配列．
-------------------- */
void stlb_k01(double tt[TETRA_V_NUM][DIM], double tp[TRIPRISM_V_NUM][DIM]);

void kadai2A_run();

#endif
