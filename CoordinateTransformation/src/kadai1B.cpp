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

	// �C�ӂ̌��_������
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		origin[i] = random_in_range(-2.0, 2.0);
	}
	// �ʒu�x�N�g����
	asPosVec4h(origin);
	// �K���ȃx�N�g��x��y������
	for (int i = 0; i < VECTOR_LEN - 1; i++)
	{
		vec0[i] = random_in_range(-1.0, 1.0);
		vec1[i] = random_in_range(-1.0, 1.0);
	}
	asDirVec4h(vec0);
	asDirVec4h(vec1);
	// �P�ʃx�N�g����
	normalize4h(vec0, vec0);
	normalize4h(vec1, vec1);

	// �K����2�̃x�N�g��(����)�ɐ����ȃx�N�g�������߂�(Z)
	cross4h(vec2, vec0, vec1);
	asDirVec4h(vec2);
	normalize4h(vec2, vec2);

	// x�x�N�g����z�x�N�g���͐����Ȃ̂ł����ɐ�����y�x�N�g�������߂�
	cross4h(vec1, vec2, vec0);
	asDirVec4h(vec1);
	normalize4h(vec1, vec1);
}

// 1.(a)���}�`������W������ɉ�]����D
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
	// X�������45�x��]
	unitMat4h(rotate_mat);
	rotateX4h(rotate_mat, 45.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_x[i], rotate_mat, arrow[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow_x);

	// y�������60�x��]
	unitMat4h(rotate_mat);
	rotateY4h(rotate_mat, 60.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_y[i], rotate_mat, arrow_x[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow_y);

	// z�������150�x��]
	unitMat4h(rotate_mat);
	rotateZ4h(rotate_mat, 150.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_z[i], rotate_mat, arrow_y[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow_z);

	plot2gnuplot();
}

// 1.(b)���}�`������W������ɉ�]����D
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

	// y�������45�x��]
	unitMat4h(rotate_mat);
	rotateY4h(rotate_mat, 60.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_y[i], rotate_mat, arrow[i]);
	}
	output_as_arrow(arrow_y);

	// z�������150�x��]
	unitMat4h(rotate_mat);
	rotateZ4h(rotate_mat, 150.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_z[i], rotate_mat, arrow_y[i]);
	}
	output_as_arrow(arrow_z);

	// X�������45�x��]
	unitMat4h(rotate_mat);
	rotateX4h(rotate_mat, 45.0 * M_PI / 180.0);
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_x[i], rotate_mat, arrow_z[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow_x);

	plot2gnuplot();
}

// 2.������p���ĔC�ӂ̌��_�ʒu�ƔC�ӂ̎����������u�E��v���W�nO1X1Y1Z1�����߂�D�v�Z���@�ƔC�Ӎ��W�n�̕\�����ʂ������D
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

	// O1X1Y1Z1���W�n�Ɗ���W�n���t�@�C���ɏ����o��
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// gnuplot�Ƀv���b�g����
	plot2gnuplot();
}


// 3.���}�`�̒��_�ʒu���C���W�nO1X1Y1Z1�ɂ����钸�_���W�l�Ƃ��ċ��߂���@�Ƃ��̌��ʂ������B
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

	// O1X1Y1Z1���W�n�Ɗ���W�n���v���b�g
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// ��ŋ��߂��x�N�g�����g���ĕϊ��s������
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1���W�n���猩�����̍��W��O0���W�Ƀv���b�g����̂ŋt�s������߂�
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	// �ϊ��s�������W�ɂ����邱�Ƃɂ����O1X1Y1Z1���W�n����݂������W�����߂�
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_from_O1[i], inv_trans_mat, arrow[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow);
	output_as_arrow(arrow_from_O1);
	//gnuplot�Ƀv���b�g
	plot2gnuplot();
}

// 4.���W�nO1X1Y1Z1������W�nO0X0Y0Z0�Ɉ�v������D���W�ϊ����̋��ߕ��������C���ۂɕϊ��������ʂ������D
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

	// O1X1Y1Z1���W�n�Ɗ���W�n���v���b�g
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// ��ŋ��߂��x�N�g�����g���ĕϊ��s������
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1���W�n���猩�����̍��W��O0���W�Ƀv���b�g����̂ŋt�s������߂�
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	mulMV4h(aligned_randomized_origin, inv_trans_mat, randomized_origin);
	mulMV4h(aligned_randomized_vec_0, inv_trans_mat, randomized_vec_0);
	mulMV4h(aligned_randomized_vec_1, inv_trans_mat, randomized_vec_1);
	mulMV4h(aligned_randomized_vec_2, inv_trans_mat, randomized_vec_2);

	output_as_coordinate(aligned_randomized_origin, aligned_randomized_vec_0, aligned_randomized_vec_1, aligned_randomized_vec_2);

	//gnuplot�Ƀv���b�g
	plot2gnuplot();
}

// 5. 4�ŋ��߂��ϊ�����p���Ė��}�`�̒��_���ړ��������ʂ��C3�ŋ��߂����_���W�l�ƈ�v���邱�Ƃ��m�F����D
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

	// O1X1Y1Z1���W�n�Ɗ���W�n���v���b�g
	output_as_coordinate(randomized_origin, randomized_vec_0, randomized_vec_1, randomized_vec_2);
	output_as_coordinate(origin, vec_0, vec_1, vec_2);

	// ��ŋ��߂��x�N�g�����g���ĕϊ��s������
	double trans_mat[VECTOR_LEN][VECTOR_LEN];
	setMatCol4h(trans_mat, randomized_vec_0, randomized_vec_1, randomized_vec_2, randomized_origin);

	// O1���W�n���猩�����̍��W��O0���W�Ƀv���b�g����̂ŋt�s������߂�
	double inv_trans_mat[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_trans_mat, trans_mat);

	// �ϊ��s�������W�ɂ����邱�Ƃɂ����O1X1Y1Z1���W�n����݂������W�����߂�
	for (int i = 0; i < ARROW_VERTEX; i++)
	{
		mulMV4h(arrow_from_O1[i], inv_trans_mat, arrow[i]);
	}
	// ���W�̏����o��
	output_as_arrow(arrow);
	output_as_arrow(arrow_from_O1);
	//gnuplot�Ƀv���b�g
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
