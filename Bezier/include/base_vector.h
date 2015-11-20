#ifndef BASE_VECTOR_H_
#define BASE_VECTOR_H_
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#define VECTOR_LEN 4
/* 関数プロトタイプ */
// ベクトル要素の代入
void setVec4h(double v[], double x, double y, double z);
// ベクトルの大きさ
double length4h(double v[]);
// 単位ベクトル
int normalize4h(double u[], double v[]);
// 逆ベクトル
void negate4h(double u[], double v[]);
// ベクトル定数倍
void scaleVec4h(double u[], double k, double v[]);
// ベクトル和
void add4h(double u[], double v[], double p[]);
// ベクトル差
void sub4h(double u[], double v[], double p[]);
// ベクトルの内積
double dot4h(double v0[], double v1[]);
// ベクトルの外積
void cross4h(double u[], double v0[], double v1[]);
// ベクトル間の角度
double angle4h(double v0[], double v1[]);
// 方向ベクトル化
void asDirVec4h(double v[]);
// 位置ベクトル化
void asPosVec4h(double v[]);

// 列ベクトルによる行列定義
void setMatCol4h(double m[VECTOR_LEN][VECTOR_LEN], double v0[], double v1[], double v2[], double p[]);

// 行列の積
void mulMM4h(double m01[VECTOR_LEN][VECTOR_LEN], double m0[VECTOR_LEN][VECTOR_LEN], double m1[VECTOR_LEN][VECTOR_LEN]);

// 行列とベクトルの積
void mulMV4h(double u[], double m[VECTOR_LEN][VECTOR_LEN], double v[]);

// 点列の変換
void map4h(double us[][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN], double vs[][VECTOR_LEN], int num);

// 平行移動
void translate4h(double m[VECTOR_LEN][VECTOR_LEN], double v[]);

// 拡大縮小
void scale4h(double m[VECTOR_LEN][VECTOR_LEN], double a, double b, double c);

// X-Y 平面対称
void mirrorXY4h(double m[VECTOR_LEN][VECTOR_LEN]);

// Y-Z 平面対称
void mirrorYZ4h(double m[VECTOR_LEN][VECTOR_LEN]);

// Z-X 平面対称
void mirrorZX4h(double m[VECTOR_LEN][VECTOR_LEN]);

// 原点対称
void mirrorO4h(double m[VECTOR_LEN][VECTOR_LEN]);

// X軸中心回転
void rotateX4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// Y軸中心回転
void rotateY4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// Z軸中心回転
void rotateZ4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// X軸中心回転
void rotateXSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// Y軸中心回転
void rotateYSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// Z軸中心回転
void rotateZSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// ゼロ行列
void zeroMat4h(double m[VECTOR_LEN][VECTOR_LEN]);

// 単位行列
void unitMat4h(double m[VECTOR_LEN][VECTOR_LEN]);

// 逆行列
int invMat4h(double im[VECTOR_LEN][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN]);

#endif