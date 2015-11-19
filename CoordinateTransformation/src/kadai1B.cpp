#include "../include/kadai1B.h"

void set_arrow(double vs[][VECTOR_LEN])
{
	double arrow[8][VECTOR_LEN - 1] = { { 2, 0, 0 }, { 1, 1, 0 }, { 1, 0.5, 0 }, { 0, 0.5, 0 }, { 0, -0.5, 0 }, { 1, -0.5, 0 }, { 1, -1, 0 }, { 2, 0, 0 } };
	for (int i = 0; i < 8; i++)
	{
		setVec4h(vs[i], arrow[i][0], arrow[i][1], arrow[i][2]);
	}
}

void set_base_coordinate(double origin[VECTOR_LEN], double vec0[VECTOR_LEN], double vec1[VECTOR_LEN], double vec2[VECTOR_LEN])
{
	origin[VECTOR_LEN-1] = 1.0;
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		origin[i] = 0.0;
		vec0[i] = 0.0;
		vec1[i] = 0.0;
		vec2[i] = 0.0;
	}
	vec0[0] = 1.0;
	vec1[1] = 1.0;
	vec2[2] = 1.0;
}

void set_random_coordinate(double origin[VECTOR_LEN], double vec0[VECTOR_LEN], double vec1[VECTOR_LEN], double vec2[VECTOR_LEN])
{

	// 任意の原点を決定
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		origin[i] = random_in_range(-2.0, 2.0);
	}
	// 位置ベクトル化
	asPosVec4h(origin);
	// 適当なベクトルxとyを決定
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		vec0[i] = random_in_range(-1.0, 1.0);
		vec1[i] = random_in_range(-1.0, 1.0);
	}
	asDirVec4h(vec0);
	asDirVec4h(vec1);
	// 単位ベクトル化
	normalize4h(vec0, vec0);
	normalize4h(vec1, vec1);

	// 適当な2つのベクトル(平面)に垂直なベクトルを求める(Z)
	cross4h(vec2, vec0, vec1);
	asDirVec4h(vec2);
	normalize4h(vec2, vec2);

	// xベクトルとzベクトルは垂直なのでこれらに垂直なyベクトルを求める
	cross4h(vec1, vec2, vec0);
	asDirVec4h(vec1);
	normalize4h(vec1, vec1);
}

// 1.(a)矢印図形を基準座標軸周りに回転する．
void kadai1B_1a_rotate()
{
	resetOutputFile();

	double arrow[ARROW_VERTEX][VECTOR_LEN];
	double arrow_x[ARROW_VERTEX][VECTOR_LEN];
	double arrow_y[ARROW_VERTEX][VECTOR_LEN];
	double arrow_z[ARROW_VERTEX][VECTOR_LEN];
	double arrow_a[ARROW_VERTEX][VECTOR_LEN];
	double arrow_b[ARROW_VERTEX][VECTOR_LEN];
	double rotate_mat[VECTOR_LEN][VECTOR_LEN];

	// 1[a]
	set_arrow(arrow);
	output_as_arrow(arrow);
	// X軸周りに45度回転
	unitMat4h(rotate_mat);
	rotateX4h(rotate_mat, 45.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_x[i], rotate_mat, arrow[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow_x);

	// y軸周りに60度回転
	unitMat4h(rotate_mat);
	rotateY4h(rotate_mat, 60.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_y[i], rotate_mat, arrow_x[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow_y);

	// z軸周りに150度回転
	unitMat4h(rotate_mat);
	rotateZ4h(rotate_mat, 150.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_z[i], rotate_mat, arrow_y[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow_z);

	plot2gnuplot();
}

// 1.(b)矢印図形を基準座標軸周りに回転する．
void kadai1B_1b_rotate()
{
	resetOutputFile();

	double arrow[ARROW_VERTEX][VECTOR_LEN];
	double arrow_x[ARROW_VERTEX][VECTOR_LEN];
	double arrow_y[ARROW_VERTEX][VECTOR_LEN];
	double arrow_z[ARROW_VERTEX][VECTOR_LEN];
	double arrow_a[ARROW_VERTEX][VECTOR_LEN];
	double arrow_b[ARROW_VERTEX][VECTOR_LEN];
	double rotate_mat[VECTOR_LEN][VECTOR_LEN];

	//1[b]
	set_arrow(arrow);
	output_as_arrow(arrow);

	// y軸周りに45度回転
	unitMat4h(rotate_mat);
	rotateY4h(rotate_mat, 60.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_y[i], rotate_mat, arrow[i]);
	}
	output_as_arrow(arrow_y);

	// z軸周りに150度回転
	unitMat4h(rotate_mat);
	rotateZ4h(rotate_mat, 150.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_z[i], rotate_mat, arrow_y[i]);
	}
	output_as_arrow(arrow_z);

	// X軸周りに45度回転
	unitMat4h(rotate_mat);
	rotateX4h(rotate_mat, 45.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_x[i], rotate_mat, arrow_z[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow_x);

	plot2gnuplot();
}

// 2.乱数を用いて任意の原点位置と任意の軸方向を持つ「右手」座標系O1X1Y1Z1を求める．計算方法と任意座標系の表示結果を示せ．
void kadai1B_2_random_coordinate()
{
	resetOutputFile();

	double arrow[ARROW_VERTEX][VECTOR_LEN];
	set_arrow(arrow);
	output_as_arrow(arrow);

	double randomized_origin[VECTOR_LEN];
	double randomized_vec_0[VECTOR_LEN];
	double randomized_vec_1[VECTOR_LEN];
	double randomized_vec_2[VECTOR_LEN];

	double origin[VECTOR_LEN];
	double vec_0[VECTOR_LEN];
	double vec_1[VECTOR_LEN];
	double vec_2[VECTOR_LEN];

	set_base_coordinate(origin, vec_0, vec_1, vec_2);
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);

	// O1X1Y1Z1座標系と基準座標系をファイルに書き出す
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// gnuplotにプロットする
	plot2gnuplot();
}


// 3.矢印図形の頂点位置を，座標系O1X1Y1Z1における頂点座標値として求める方法とその結果を示せ。
void kadai1B_3_arrow_pos_as_random_coordinate()
{
	resetOutputFile();

	double arrow[ARROW_VERTEX][VECTOR_LEN];
	double arrow_from_O1[ARROW_VERTEX][VECTOR_LEN];
	set_arrow(arrow);

	double origin[VECTOR_LEN];
	double vec_0[VECTOR_LEN];
	double vec_1[VECTOR_LEN];
	double vec_2[VECTOR_LEN];

	double randomized_origin[VECTOR_LEN];
	double randomized_vec_0[VECTOR_LEN];
	double randomized_vec_1[VECTOR_LEN];
	double randomized_vec_2[VECTOR_LEN];

	set_base_coordinate(origin, vec_0, vec_1, vec_2);
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);

	// O1X1Y1Z1座標系と基準座標系をプロット
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// 上で求めたベクトルを使って変換行列を作る
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1座標系から見た矢印の座標をO0座標にプロットするので逆行列を求める
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	// 変換行列を矢印座標にかけることによってO1X1Y1Z1座標系からみた矢印座標を求める
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_from_O1[i], inv_trans_mat, arrow[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow);
	output_as_arrow(arrow_from_O1);
	//gnuplotにプロット
	plot2gnuplot();
}

// 4.座標系O1X1Y1Z1を基準座標系O0X0Y0Z0に一致させる．座標変換式の求め方を示し，実際に変換した結果を示せ．
void kadai1B_4_align()
{
	resetOutputFile();

	double origin[VECTOR_LEN];
	double vec_0[VECTOR_LEN];
	double vec_1[VECTOR_LEN];
	double vec_2[VECTOR_LEN];

	double randomized_origin[VECTOR_LEN];
	double randomized_vec_0[VECTOR_LEN];
	double randomized_vec_1[VECTOR_LEN];
	double randomized_vec_2[VECTOR_LEN];

	set_base_coordinate(origin, vec_0, vec_1, vec_2);
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);

	double aligned_randomized_origin[VECTOR_LEN];
	double aligned_randomized_vec_0[VECTOR_LEN];
	double aligned_randomized_vec_1[VECTOR_LEN];
	double aligned_randomized_vec_2[VECTOR_LEN];

	// O1X1Y1Z1座標系と基準座標系をプロット
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// 上で求めたベクトルを使って変換行列を作る
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1座標系から見た矢印の座標をO0座標にプロットするので逆行列を求める
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	mulMV4h(aligned_randomized_origin, inv_trans_mat, randomized_origin);
	mulMV4h(aligned_randomized_vec_0, inv_trans_mat, randomized_vec_0);
	mulMV4h(aligned_randomized_vec_1, inv_trans_mat, randomized_vec_1);
	mulMV4h(aligned_randomized_vec_2, inv_trans_mat, randomized_vec_2);

	output_as_coordinate(aligned_randomized_origin, aligned_randomized_vec_0, aligned_randomized_vec_1, aligned_randomized_vec_2);

	//gnuplotにプロット
	plot2gnuplot();
}

// 5. 4で求めた変換式を用いて矢印図形の頂点を移動した結果が，3で求めた頂点座標値と一致することを確認せよ．
void kadai1B_5_correspond()
{
	resetOutputFile();

	double arrow[ARROW_VERTEX][VECTOR_LEN];
	double arrow_from_O1[ARROW_VERTEX][VECTOR_LEN];
	set_arrow(arrow);

	double origin[VECTOR_LEN];
	double vec_0[VECTOR_LEN];
	double vec_1[VECTOR_LEN];
	double vec_2[VECTOR_LEN];

	double randomized_origin[VECTOR_LEN];
	double randomized_vec_0[VECTOR_LEN];
	double randomized_vec_1[VECTOR_LEN];
	double randomized_vec_2[VECTOR_LEN];

	set_base_coordinate(origin, vec_0, vec_1, vec_2);
	set_random_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);

	// O1X1Y1Z1座標系と基準座標系をプロット
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// 上で求めたベクトルを使って変換行列を作る
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1座標系から見た矢印の座標をO0座標にプロットするので逆行列を求める
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	// 変換行列を矢印座標にかけることによってO1X1Y1Z1座標系からみた矢印座標を求める
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_from_O1[i], inv_trans_mat, arrow[i]);
	}
	// 座標の書き出し
	output_as_arrow(arrow);
	output_as_arrow(arrow_from_O1);
	//gnuplotにプロット
	plot2gnuplot();

}

int kadai1B_run()
{
	kadai1B_1a_rotate();

	kadai1B_1b_rotate();

	kadai1B_2_random_coordinate();
	
	kadai1B_3_arrow_pos_as_random_coordinate();

	kadai1B_4_align();

	kadai1B_5_correspond();

	return 0;
}
