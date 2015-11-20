#ifndef BEZIER_H_
#define BEZIER_H_

#define HDIM 4
#define BDIM 3

// �p�����[�^�x�N�g��(t0, t1, t2, t3)��Ԃ�
// pv : �p�����[�^�x�N�g�����i�[����z��, t : �p�����[�^�D0<= t <= 1�̎���
void set_param_vector(double pv[BDIM + 1], double t);

// �s��ƃx�N�g���̐ς����߂�D�W���s��ƃp�����[�^�x�N�g���̐ςɗp����
// u : �ω��Z�̌��ʓ�����x�N�g���D, mb : 3���̃x�W�F�Ȑ��p�W���s��D, v : �p�����[�^�x�N�g��
void mulMVb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1]);

// ����_���X�g�ƃx�N�g���̐ς����߂�D
// u : �ω��Z�̌��ʓ�����x�N�g���D, cps : ����_���X�g���i�[����2�����z��D, v : �x�N�g���D
void mulLCpVb(double u[HDIM], double cps[BDIM + 1][HDIM], double v[BDIM + 1]);

// �p�����[�^ t �ɑΉ�����3���̃x�W�F�Ȑ���̓_�����߂�D
// q : �x�W�F�Ȑ���̓_, mb : 3���̃x�W�F�Ȑ��p�W���s��, cps : ����_���X�g���i�[����2�����z��, t : �p�����[�^�D0<= t <= 1�̎����D
void on_bezier3_curve(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][HDIM], double t);

#endif