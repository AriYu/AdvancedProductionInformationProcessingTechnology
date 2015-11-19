#include "../include/kadai2A.h"

void set_tetra(double vs[][DIM])
{
	int i = 0;
	setVec4h(vs[i], 1, 0, 0); i++;
	setVec4h(vs[i], -0.5, 0.5, 0); i++;
	setVec4h(vs[i], -0.5, -0.5, 0); i++;
	setVec4h(vs[i], 0, 0, 2);
}

void set_triprism(double vs[][DIM], double h)
{
	int i = 0;
	setVec4h(vs[i], 1, 0, 0); i++;
	setVec4h(vs[i], -0.5, 0.5, 0); i++;
	setVec4h(vs[i], -0.5, -0.5, 0); i++;
	setVec4h(vs[i], 1, 0, h); i++;
	setVec4h(vs[i], -0.5, 0.5, h); i++;
	setVec4h(vs[i], -0.5, -0.5, h);
}


void norm_triangle(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM])
{
	double v01[DIM], v02[DIM];
	setVec4h(v01, v1[0] - v0[0], v1[1] - v0[1], v1[2] - v0[2]);
	setVec4h(v02, v2[0] - v0[0], v2[1] - v0[1], v2[2] - v0[2]);
	cross4h(n, v01, v02);
	asDirVec4h(n);
	normalize4h(n, n);
}

void prStlProlog(char *label)
{
	printf("solid %s\n", label);
}

void prStlEpilog(char *label)
{
	printf("endsolid %s\n", label);
}


void prStlFacet(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM])
{
	printf("  facet normal %3.6e %3.6e %3.6e\n", n[0], n[1], n[2]);
	printf("    outer loop\n");
	printf("      vertex %15.6e %15.6e %15.6e\n", v0[0], v0[1], v0[2]);
	printf("      vertex %15.6e %15.6e %15.6e\n", v1[0], v1[1], v1[2]);
	printf("      vertex %15.6e %15.6e %15.6e\n", v2[0], v2[1], v2[2]);
	printf("    endloop\n");
	printf("  endfacet\n");
}

void prStlProlog2file(char *label, FILE *outputfile)
{
	fprintf(outputfile, "solid %s\n", label);
}

void prStlEpilog2file(char *label, FILE *outputfile)
{
	fprintf(outputfile,"endsolid %s\n\n", label);
}

void prStlFacet2file(double n[DIM], double v0[DIM], double v1[DIM], double v2[DIM], FILE *outputfile)
{
	fprintf(outputfile,"  facet normal %3.6e %3.6e %3.6e\n", n[0], n[1], n[2]);
	fprintf(outputfile,"    outer loop\n");
	fprintf(outputfile,"      vertex %15.6e %15.6e %15.6e\n", v0[0], v0[1], v0[2]);
	fprintf(outputfile,"      vertex %15.6e %15.6e %15.6e\n", v1[0], v1[1], v1[2]);
	fprintf(outputfile,"      vertex %15.6e %15.6e %15.6e\n", v2[0], v2[1], v2[2]);
	fprintf(outputfile,"    endloop\n");
	fprintf(outputfile,"  endfacet\n");
}

void prStlTetra(double vs[][DIM], char *label)
{
	double n[DIM];
	int i, j, s = (TETRA_V_NUM - 1); 
	prStlProlog(label); 
	for (i = 0; i < s; i++) {
		j = (i + 1) % s;
		norm_triangle(n, vs[s], vs[i], vs[j]); 
		prStlFacet(n, vs[s], vs[i], vs[j]);
	}
	norm_triangle(n, vs[2], vs[1], vs[0]); 
	prStlFacet(n, vs[2], vs[1], vs[0]);
	prStlEpilog(label);
}

void prStlTetra2file(double vs[][DIM], char *label, FILE *outputfile)
{
	double n[DIM];
	int i, j, s = (TETRA_V_NUM - 1); 
	prStlProlog2file(label, outputfile);
	for (i = 0; i < s; i++) {
		j = (i + 1) % s;
		norm_triangle(n, vs[s], vs[i], vs[j]); 
		prStlFacet2file(n, vs[s], vs[i], vs[j], outputfile);
	}
	norm_triangle(n, vs[2], vs[1], vs[0]); 
	prStlFacet2file(n, vs[2], vs[1], vs[0], outputfile);
	prStlEpilog2file(label,outputfile);
}


void prStlTriprism2file(double vs[][DIM], char *label, FILE *outputfile)
{
	double n[DIM];
	prStlProlog2file(label, outputfile);

	norm_triangle(n, vs[2], vs[1], vs[0]);
	prStlFacet2file(n, vs[2], vs[1], vs[0], outputfile);

	norm_triangle(n, vs[1], vs[3], vs[0]);
	prStlFacet2file(n, vs[1], vs[3], vs[0], outputfile);

	norm_triangle(n, vs[4], vs[3], vs[1]);
	prStlFacet2file(n, vs[4], vs[3], vs[1], outputfile);

	norm_triangle(n, vs[3], vs[2], vs[0]);
	prStlFacet2file(n, vs[3], vs[2], vs[0], outputfile);

	norm_triangle(n, vs[3], vs[5], vs[2]);
	prStlFacet2file(n, vs[3], vs[5], vs[2], outputfile);

	norm_triangle(n, vs[2], vs[4], vs[1]);
	prStlFacet2file(n, vs[2], vs[4], vs[1], outputfile);

	norm_triangle(n, vs[5], vs[4], vs[2]);
	prStlFacet2file(n, vs[5], vs[4], vs[2], outputfile);

	norm_triangle(n, vs[4], vs[5], vs[3]);
	prStlFacet2file(n, vs[4], vs[5], vs[3], outputfile);

	prStlEpilog2file(label, outputfile);
}

/* --------------------
上記補助関数の利用例．
各立体の頂点データは座標変換などにも使うため，
頂点データの入れ物＝配列は，この関数の外で宣言する．
tt (O)：４面体の頂点を格納する配列．
tp (O)：３角柱の頂点を格納する配列．
-------------------- */
void stlb_k01(double tt[TETRA_V_NUM][DIM], double tp[TRIPRISM_V_NUM][DIM])
{
	FILE *outputfile_tetra;
	outputfile_tetra = fopen("../output/stl/Tetra01.stl", "w");
	if (outputfile_tetra == NULL)
	{
		printf("cannot open [Tetra01.stl]\n");
	}
	set_tetra(tt);
	prStlTetra2file(tt, "Tetra01",outputfile_tetra);
	fclose(outputfile_tetra);

	FILE *outputfile_triprism;
	outputfile_triprism = fopen("../output/stl/Triprism01.stl", "w");
	if (outputfile_triprism == NULL)
	{
		printf("cannot open [Triprism01.stl]\n");
	}
	set_triprism(tp, 2);
	prStlTriprism2file(tp, "Triprism01",outputfile_triprism);
	fclose(outputfile_triprism);
}

void kadai2A_1()
{
	//4面体座標指定用配列
	double tetra_pos[4][DIM];

	//3角柱座標指定用配列
	double triprism_pos[6][DIM];

	stlb_k01(tetra_pos, triprism_pos);
}

void kadai2A_2()
{
	//4面体座標指定用配列
	double tetra_pos[TETRA_V_NUM][DIM];
	double transed_tetra_pos[TETRA_V_NUM][DIM];
	set_tetra(tetra_pos);

	//3角柱座標指定用配列
	double triprism_pos[TRIPRISM_V_NUM][DIM];
	double transed_triprism_pos[TRIPRISM_V_NUM][DIM];
	set_triprism(triprism_pos,2);

	double randomized_origin[VECTOR_LEN];
	double randomized_vec_0[VECTOR_LEN];
	double randomized_vec_1[VECTOR_LEN];
	double randomized_vec_2[VECTOR_LEN];

	// 変換行列
	double trans_mat[VECTOR_LEN][VECTOR_LEN];

	// 三角錐用の乱数座標系
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);

	// 上で求めたベクトルを使って変換行列を作る
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);
	printMat(trans_mat);
	// 変換行列を用いて三角錐を変換
	for (int i = 0; i < TETRA_V_NUM; i++)
	{
		mulMV4h(transed_tetra_pos[i], trans_mat, tetra_pos[i]);
	}

	// 三角柱用の乱数座標系
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	// 平行移動と回転
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// 変換行列を用いて三角柱を変換
	for (int i = 0; i < TRIPRISM_V_NUM; i++)
	{
		mulMV4h(transed_triprism_pos[i], trans_mat, triprism_pos[i]);
	}

	// 結果をstlに書き出す
	FILE *outputfile;
	outputfile = fopen("../output/stl/random.stl", "w");
	if (outputfile == NULL)
	{
		printf("cannot open [random.stl]\n");
	}
	prStlTetra2file(tetra_pos, "Tetra01", outputfile);
	prStlTetra2file(transed_tetra_pos, "Tetra01_transed", outputfile);
	prStlTriprism2file(transed_triprism_pos, "Triprism01_transed", outputfile);
	fclose(outputfile);
}

void kadai2A_run()
{
	kadai2A_1();
	kadai2A_2();
}