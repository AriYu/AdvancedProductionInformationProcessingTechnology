#include "../include/base_vector.h"

// ベクトル要素の代入
void setVec4h(double v[], double x, double y, double z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 1;
}

// ベクトルの大きさ
double length4h(double v[])
{
	double len = 0;
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		len += pow(v[i], 2);
	}
	return sqrt(len);
}

// 単位ベクトル
int normalize4h(double u[], double v[])
{
	double length = length4h(v);
	if (length == 0.0){
		return 0;
	}
	else{
		for (int i = 0; i < VECTOR_LEN; i++)
		{
			u[i] = v[i] / length;
		}
		//u[VECTOR_LEN - 1] = 0;
	}
	return 1;
}

// 逆ベクトル
void negate4h(double u[], double v[])
{
	for (int i = 0; i < VECTOR_LEN-1; i++)
	{
		u[i] = -v[i];
	}
	u[VECTOR_LEN - 1] = 1;
}

// ベクトル定数倍
void scaleVec4h(double u[], double k, double v[])
{
	for (int i = 0; i < VECTOR_LEN-1; i++)
	{
		u[i] = k * v[i];
	}
	u[VECTOR_LEN - 1] = 1;
}

// ベクトル和
void add4h(double u[], double v[], double p[])
{
	for (int i = 0; i < VECTOR_LEN-1; i++)
	{
		u[i] = v[i] + p[i];
	}
	u[VECTOR_LEN - 1] = 1;
}
// ベクトル差
void sub4h(double u[], double v[], double p[])
{
	for (int i = 0; i < VECTOR_LEN-1; i++)
	{
		u[i] = v[i] - p[i];
	}
	u[VECTOR_LEN - 1] = 1;
}

// ベクトルの内積
double dot4h(double v0[], double v1[])
{
	double sum = 0;
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		sum += (v0[i] * v1[i]);
	}
	return sum;
}
// ベクトルの外積
void cross4h(double u[], double v0[], double v1[])
{
	u[0] = v0[1] * v1[2] - v0[2] * v1[1];
	u[1] = v0[2] * v1[0] - v0[0] * v1[2];
	u[2] = v0[0] * v1[1] - v0[1] * v1[0];
	//u[3] = 1;
}
// ベクトル間の角度
double angle4h(double v0[], double v1[])
{
	double cos_theta = 0;
	double length_0 = length4h(v0);
	double length_1 = length4h(v1);
	if (length_0 != 0.0 && length_1 != 0.0)
	{
		cos_theta = dot4h(v0, v1) / (length_0 * length_1);
		return acos(cos_theta);
	}
	else
	{
		return 0;
	}
}
// 方向ベクトル化
void asDirVec4h(double v[])
{
	v[VECTOR_LEN-1] = 0;
}
// 位置ベクトル化
void asPosVec4h(double v[])
{
	v[VECTOR_LEN-1] = 1;
}

// 列ベクトルによる行列定義
// m[行番号][列番号]
void setMatCol4h(double m[VECTOR_LEN][VECTOR_LEN], double v0[], double v1[], double v2[], double p[])
{
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		m[i][0] = v0[i];
		m[i][1] = v1[i];
		m[i][2] = v2[i];
		m[i][3] = p[i];
	}
}

// 行列の積
void mulMM4h(double m01[VECTOR_LEN][VECTOR_LEN], double m0[VECTOR_LEN][VECTOR_LEN], double m1[VECTOR_LEN][VECTOR_LEN])
{
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		for (int j = 0; j < VECTOR_LEN; j++)
		{
			m01[i][j] = 0;
			for (int k = 0; k < VECTOR_LEN; k++)
			{
				m01[i][j] += (m0[i][k] * m1[k][j]);
			}
		}
	}
}

// 行列とベクトルの積
void mulMV4h(double u[], double m[VECTOR_LEN][VECTOR_LEN], double v[])
{
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		u[i] = 0;
		for (int j = 0; j < VECTOR_LEN; j++)
		{
			u[i] += (m[i][j] * v[j]);
		}
	}
}

// 点列の変換
void map4h(double us[][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN], double vs[][VECTOR_LEN], int num)
{
	for (int i = 0; i < num; i++)
	{
		mulMV4h(us[i], m, vs[i]);
	}
}

// 平行移動
void translate4h(double m[VECTOR_LEN][VECTOR_LEN], double v[])
{
	//unitMat4h(m);
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		m[i][VECTOR_LEN - 1] = v[i];
	}
}

// 拡大縮小
void scale4h(double m[VECTOR_LEN][VECTOR_LEN], double a, double b, double c)
{
	unitMat4h(m);
	m[0][0] = a;
	m[1][1] = b;
	m[2][2] = c;
}

// X-Y 平面対称
void mirrorXY4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	unitMat4h(m);
	m[2][2] = -1;
}

// Y-Z 平面対称
void mirrorYZ4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	unitMat4h(m);
	m[0][0] = -1;
}

// Z-X 平面対称
void mirrorZX4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	unitMat4h(m);
	m[1][1] = -1;
}

// 原点対称
void mirrorO4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	unitMat4h(m);
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		m[i][i] = -1;
	}
}

// X軸中心回転
void rotateX4h(double m[VECTOR_LEN][VECTOR_LEN], double a)
{
	//unitMat4h(m);
	m[1][1] = cos(a);
	m[1][2] = -sin(a);
	m[2][1] = sin(a);
	m[2][2] = cos(a);
}

// Y軸中心回転
void rotateY4h(double m[VECTOR_LEN][VECTOR_LEN], double a)
{
	//unitMat4h(m);
	m[0][0] = cos(a);
	m[0][2] = sin(a);
	m[2][0] = -sin(a);
	m[2][2] = cos(a);
}

// Z軸中心回転
void rotateZ4h(double m[VECTOR_LEN][VECTOR_LEN], double a)
{
	//unitMat4h(m);
	m[0][0] = cos(a);
	m[0][1] = -sin(a);
	m[1][0] = sin(a);
	m[1][1] = cos(a);
}

// X軸中心回転, sv : sin(theta), cv : cos(theta)
void rotateXSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv)
{
	unitMat4h(m);
	m[1][1] = cv;
	m[1][2] = -sv;
	m[2][1] = sv;
	m[2][2] = cv;
}

// Y軸中心回転, sv : sin(theta), cv : cos(theta)
void rotateYSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv)
{
	unitMat4h(m);
	m[0][0] = cv;
	m[0][2] = -sv;
	m[2][0] = sv;
	m[2][2] = cv;
}

// Z軸中心回転, sv : sin(theta), cv : cos(theta)
void rotateZSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv)
{
	unitMat4h(m);
	m[0][0] = cv;
	m[0][1] = -sv;
	m[1][0] = sv;
	m[1][1] = cv;
}

// ゼロ行列
void zeroMat4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		for (int j = 0; j < VECTOR_LEN; j++)
		{
			m[i][j] = 0.0;
		}
	}
}

// 単位行列
void unitMat4h(double m[VECTOR_LEN][VECTOR_LEN])
{
	zeroMat4h(m);
	for (int i = 0; i < VECTOR_LEN; i++)
	{
		m[i][i] = 1.0;
	}
}

// 逆行列
int invMat4h(double im[VECTOR_LEN][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN])
{
	unitMat4h(im);
	double det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) 
					+(-1)* m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
					+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	if (det == 0.0)
	{
		printf("inverse Matrix is not exist !!!");
		return -1;
	}
	else
	{
		im[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
		im[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
		im[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
		im[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
		im[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
		im[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
		im[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
		im[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
		im[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
		im[0][3] = -1 * (im[0][0] * m[0][3] + im[0][1] * m[1][3] + im[0][2] * m[2][3]);
		im[1][3] = -1 * (im[1][0] * m[0][3] + im[1][1] * m[1][3] + im[1][2] * m[2][3]);
		im[2][3] = -1 * (im[2][0] * m[0][3] + im[2][1] * m[1][3] + im[2][2] * m[2][3]);
		im[3][3] = 1;
		return 0;
	}
}
