#ifndef BASE_VECTOR_H_
#define BASE_VECTOR_H_
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#define VECTOR_LEN 4
/* �֐��v���g�^�C�v */
// �x�N�g���v�f�̑��
void setVec4h(double v[], double x, double y, double z);
// �x�N�g���̑傫��
double length4h(double v[]);
// �P�ʃx�N�g��
int normalize4h(double u[], double v[]);
// �t�x�N�g��
void negate4h(double u[], double v[]);
// �x�N�g���萔�{
void scaleVec4h(double u[], double k, double v[]);
// �x�N�g���a
void add4h(double u[], double v[], double p[]);
// �x�N�g����
void sub4h(double u[], double v[], double p[]);
// �x�N�g���̓���
double dot4h(double v0[], double v1[]);
// �x�N�g���̊O��
void cross4h(double u[], double v0[], double v1[]);
// �x�N�g���Ԃ̊p�x
double angle4h(double v0[], double v1[]);
// �����x�N�g����
void asDirVec4h(double v[]);
// �ʒu�x�N�g����
void asPosVec4h(double v[]);

// ��x�N�g���ɂ��s���`
void setMatCol4h(double m[VECTOR_LEN][VECTOR_LEN], double v0[], double v1[], double v2[], double p[]);

// �s��̐�
void mulMM4h(double m01[VECTOR_LEN][VECTOR_LEN], double m0[VECTOR_LEN][VECTOR_LEN], double m1[VECTOR_LEN][VECTOR_LEN]);

// �s��ƃx�N�g���̐�
void mulMV4h(double u[], double m[VECTOR_LEN][VECTOR_LEN], double v[]);

// �_��̕ϊ�
void map4h(double us[][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN], double vs[][VECTOR_LEN], int num);

// ���s�ړ�
void translate4h(double m[VECTOR_LEN][VECTOR_LEN], double v[]);

// �g��k��
void scale4h(double m[VECTOR_LEN][VECTOR_LEN], double a, double b, double c);

// X-Y ���ʑΏ�
void mirrorXY4h(double m[VECTOR_LEN][VECTOR_LEN]);

// Y-Z ���ʑΏ�
void mirrorYZ4h(double m[VECTOR_LEN][VECTOR_LEN]);

// Z-X ���ʑΏ�
void mirrorZX4h(double m[VECTOR_LEN][VECTOR_LEN]);

// ���_�Ώ�
void mirrorO4h(double m[VECTOR_LEN][VECTOR_LEN]);

// X�����S��]
void rotateX4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// Y�����S��]
void rotateY4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// Z�����S��]
void rotateZ4h(double m[VECTOR_LEN][VECTOR_LEN], double a);

// X�����S��]
void rotateXSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// Y�����S��]
void rotateYSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// Z�����S��]
void rotateZSC4h(double m[VECTOR_LEN][VECTOR_LEN], double sv, double cv);

// �[���s��
void zeroMat4h(double m[VECTOR_LEN][VECTOR_LEN]);

// �P�ʍs��
void unitMat4h(double m[VECTOR_LEN][VECTOR_LEN]);

// �t�s��
int invMat4h(double im[VECTOR_LEN][VECTOR_LEN], double m[VECTOR_LEN][VECTOR_LEN]);

#endif