#include "../include/kadai2B.h"
#include "../include/kadai2A.h"

// 1.��������
void kadai2B_1()
{
	printf("���|�[�g�ɏ���\n");
}

// 2. �A�[���̐��@�Ɗe�֐߂̉�]�p���w�肷��ƁC�e�֐߂̍��W�n([X0, Y0, Z0] ~ [X5, Y5, Z5])��������v�Z�v���O�������쐬����D 
void kadai2B_2()
{
	double L1 = 3.0;
	double L3 = 2.0;
	double L5 = 1.0;
	double T1 = 45.0;
	double T2 = 30.0;
	double T3 = 135.0;
	double T4 = -30.0;
	double T5 = 60.0;
	double origin[COORDINATE_NUM][VECTOR_LEN];
	double vec_0[COORDINATE_NUM][VECTOR_LEN];
	double vec_1[COORDINATE_NUM][VECTOR_LEN];
	double vec_2[COORDINATE_NUM][VECTOR_LEN];
	set_base_coordinate(origin[0], vec_0[0], vec_1[0], vec_2[0]);
	output_as_coordinate(origin[0], vec_0[0], vec_1[0], vec_2[0]);

	double transform_mat[8][VECTOR_LEN][VECTOR_LEN];
	double temporary_mat[16][VECTOR_LEN][VECTOR_LEN];
	double temporary_vec[VECTOR_LEN];

	//������
	for (int i = 0; i < 8; i++)
	{
		unitMat4h(transform_mat[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		unitMat4h(temporary_mat[i]);
	}
	for (int i = 0; i < COORDINATE_NUM; i++)
	{
		asDirVec4h(vec_0[i]);
		asDirVec4h(vec_1[i]);
		asDirVec4h(vec_2[i]);
	}
	// 1���� z�������� L1/2, z������� T1
	double translate_vector[VECTOR_LEN];
	setVec4h(translate_vector, 0.0, 0.0, L1 / 2.0);
	translate4h(transform_mat[0], translate_vector);
	rotateZ4h(transform_mat[0], T1*3.14 / 180.0);
	printf("[0]");
	printMat(transform_mat[0]);

	// 2���� z�������� L1/2
	setVec4h(translate_vector, 0.0, 0.0, L1 / 2.0);
	translate4h(transform_mat[1], translate_vector);
	printf("[1]");
	printMat(transform_mat[1]);

	// 3���� x������� T2
	rotateX4h(transform_mat[2], T2*3.14 / 180.0);
	printf("[2]");
	printMat(transform_mat[2]);

	// 4���� y�������� L3/2, y������� T3
	setVec4h(translate_vector, 0.0, L3 / 2.0, 0.0);
	translate4h(transform_mat[3], translate_vector);
	rotateY4h(transform_mat[3], T3*3.14 / 180.0);
	printf("[3]");
	printMat(transform_mat[3]);

	// 5���� y�������Ɂ@L3/2
	setVec4h(translate_vector, 0.0, L3 / 2.0, 0.0);
	translate4h(transform_mat[4], translate_vector);
	printf("[4]");
	printMat(transform_mat[4]);

	// 6���� x������� T4
	rotateX4h(transform_mat[5], T4*3.14 / 180.0);
	printf("[5]");
	printMat(transform_mat[5]);

	// 7���� y�������� L5/2, y�������T5
	setVec4h(translate_vector, 0.0, L5 / 2.0, 0.0);
	translate4h(transform_mat[6], translate_vector);
	rotateY4h(transform_mat[6], T5*3.14 / 180.0);
	printf("[6]");
	printMat(transform_mat[6]);

	// EndEffect y�������� L5/2
	setVec4h(translate_vector, 0.0, L5 / 2.0, 0.0);
	translate4h(transform_mat[7], translate_vector);
	printf("[7]");
	printMat(transform_mat[7]);

	//���ꂼ��ϊ����Ă���
	// 1�Ԗ�
	mulMV4h(origin[1], transform_mat[0], origin[0]);
	mulMV4h(vec_0[1], transform_mat[0], vec_0[0]);
	mulMV4h(vec_1[1], transform_mat[0], vec_1[0]);
	mulMV4h(vec_2[1], transform_mat[0], vec_2[0]);
	output_as_coordinate(origin[1], vec_0[1], vec_1[1], vec_2[1]);
	// 2�Ԗ�
	mulMM4h(temporary_mat[0], transform_mat[0], transform_mat[1]);
	mulMV4h(origin[2], temporary_mat[0], origin[0]);
	mulMV4h(vec_0[2], temporary_mat[0], vec_0[0]);
	mulMV4h(vec_1[2], temporary_mat[0], vec_1[0]);
	mulMV4h(vec_2[2], temporary_mat[0], vec_2[0]);
	output_as_coordinate(origin[2], vec_0[2], vec_1[2], vec_2[2]);
	// 3�Ԗ�
	mulMM4h(temporary_mat[1], temporary_mat[0], transform_mat[2]);
	mulMV4h(origin[3], temporary_mat[1], origin[0]);
	mulMV4h(vec_0[3], temporary_mat[1], vec_0[0]);
	mulMV4h(vec_1[3], temporary_mat[1], vec_1[0]);
	mulMV4h(vec_2[3], temporary_mat[1], vec_2[0]);
	output_as_coordinate(origin[3], vec_0[3], vec_1[3], vec_2[3]);
	// 4�Ԗ�
	mulMM4h(temporary_mat[2], temporary_mat[1], transform_mat[3]);
	mulMV4h(origin[4], temporary_mat[2], origin[0]);
	mulMV4h(vec_0[4], temporary_mat[2], vec_0[0]);
	mulMV4h(vec_1[4], temporary_mat[2], vec_1[0]);
	mulMV4h(vec_2[4], temporary_mat[2], vec_2[0]);
	output_as_coordinate(origin[4], vec_0[4], vec_1[4], vec_2[4]);
	// 5�Ԗ�
	mulMM4h(temporary_mat[3], temporary_mat[2], transform_mat[4]);
	mulMV4h(origin[5], temporary_mat[3], origin[0]);
	mulMV4h(vec_0[5], temporary_mat[3], vec_0[0]);
	mulMV4h(vec_1[5], temporary_mat[3], vec_1[0]);
	mulMV4h(vec_2[5], temporary_mat[3], vec_2[0]);
	output_as_coordinate(origin[5], vec_0[5], vec_1[5], vec_2[5]);
	// 6�Ԗ�
	mulMM4h(temporary_mat[4], temporary_mat[3], transform_mat[5]);
	mulMV4h(origin[6], temporary_mat[4], origin[0]);
	mulMV4h(vec_0[6], temporary_mat[4], vec_0[0]);
	mulMV4h(vec_1[6], temporary_mat[4], vec_1[0]);
	mulMV4h(vec_2[6], temporary_mat[4], vec_2[0]);
	output_as_coordinate(origin[6], vec_0[6], vec_1[6], vec_2[6]);
	// 7�Ԗ�
	mulMM4h(temporary_mat[5], temporary_mat[4], transform_mat[6]);
	mulMV4h(origin[7], temporary_mat[5], origin[0]);
	mulMV4h(vec_0[7], temporary_mat[5], vec_0[0]);
	mulMV4h(vec_1[7], temporary_mat[5], vec_1[0]);
	mulMV4h(vec_2[7], temporary_mat[5], vec_2[0]);
	output_as_coordinate(origin[7], vec_0[7], vec_1[7], vec_2[7]);
	// 8�Ԗ�
	mulMM4h(temporary_mat[6], temporary_mat[5], transform_mat[7]);
	mulMV4h(origin[8], temporary_mat[6], origin[0]);
	mulMV4h(vec_0[8], temporary_mat[6], vec_0[0]);
	mulMV4h(vec_1[8], temporary_mat[6], vec_1[0]);
	mulMV4h(vec_2[8], temporary_mat[6], vec_2[0]);
	output_as_coordinate(origin[8], vec_0[8], vec_1[8], vec_2[8]);

	//gnuplot�Ƀv���b�g
	plot2gnuplot();
}

void kadai2B_3()
{
	double L1 = 3.0;
	double L3 = 2.0;
	double L5 = 1.0;
	double T1 = 45.0;
	double T2 = 30.0;
	double T3 = 135.0;
	double T4 = -30.0;
	double T5 = 60.0;
	double origin[COORDINATE_NUM][VECTOR_LEN];
	double vec_0[COORDINATE_NUM][VECTOR_LEN];
	double vec_1[COORDINATE_NUM][VECTOR_LEN];
	double vec_2[COORDINATE_NUM][VECTOR_LEN];
	set_base_coordinate(origin[0], vec_0[0], vec_1[0], vec_2[0]);
	output_as_coordinate(origin[0], vec_0[0], vec_1[0], vec_2[0]);

	double transform_mat[8][VECTOR_LEN][VECTOR_LEN];
	double temporary_mat[16][VECTOR_LEN][VECTOR_LEN];
	double temporary_vec[VECTOR_LEN];

	//������
	for (int i = 0; i < 8; i++)
	{
		unitMat4h(transform_mat[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		unitMat4h(temporary_mat[i]);
	}
	for (int i = 0; i < COORDINATE_NUM; i++)
	{
		asDirVec4h(vec_0[i]);
		asDirVec4h(vec_1[i]);
		asDirVec4h(vec_2[i]);
	}
	// 1���� z������� T1
	double translate_vector[VECTOR_LEN];
	setVec4h(translate_vector, 0.0, 0.0, 0);
	translate4h(transform_mat[0], translate_vector);
	rotateZ4h(transform_mat[0], T1*3.14 / 180.0);
	printf("[0]");
	printMat(transform_mat[0]);

	// 2���� z�������� L1
	setVec4h(translate_vector, 0.0, 0.0, L1);
	translate4h(transform_mat[1], translate_vector);
	printf("[1]");
	printMat(transform_mat[1]);

	// 3���� x������� T2
	rotateX4h(transform_mat[2], T2*3.14 / 180.0);
	printf("[2]");
	printMat(transform_mat[2]);

	// 4����  y������� T3
	setVec4h(translate_vector, 0.0, 0.0, 0.0);
	translate4h(transform_mat[3], translate_vector);
	rotateY4h(transform_mat[3], T3*3.14 / 180.0);
	printf("[3]");
	printMat(transform_mat[3]);

	// 5���� y�������Ɂ@L3
	setVec4h(translate_vector, 0.0, L3, 0.0);
	translate4h(transform_mat[4], translate_vector);
	printf("[4]");
	printMat(transform_mat[4]);

	// 6���� x������� T4
	rotateX4h(transform_mat[5], T4*3.14 / 180.0);
	printf("[5]");
	printMat(transform_mat[5]);

	// 7���� y�������T5
	setVec4h(translate_vector, 0.0, 0, 0.0);
	translate4h(transform_mat[6], translate_vector);
	rotateY4h(transform_mat[6], T5*3.14 / 180.0);
	printf("[6]");
	printMat(transform_mat[6]);

	// EndEffect y�������� L5
	setVec4h(translate_vector, 0.0, L5, 0.0);
	translate4h(transform_mat[7], translate_vector);
	printf("[7]");
	printMat(transform_mat[7]);

	//���ꂼ��ϊ����Ă���
	// 1�Ԗ�
	mulMV4h(origin[1], transform_mat[0], origin[0]);
	mulMV4h(vec_0[1], transform_mat[0], vec_0[0]);
	mulMV4h(vec_1[1], transform_mat[0], vec_1[0]);
	mulMV4h(vec_2[1], transform_mat[0], vec_2[0]);
	output_as_coordinate(origin[1], vec_0[1], vec_1[1], vec_2[1]);
	// 2�Ԗ�
	mulMM4h(temporary_mat[0], transform_mat[0], transform_mat[1]);
	mulMV4h(origin[2], temporary_mat[0], origin[0]);
	mulMV4h(vec_0[2], temporary_mat[0], vec_0[0]);
	mulMV4h(vec_1[2], temporary_mat[0], vec_1[0]);
	mulMV4h(vec_2[2], temporary_mat[0], vec_2[0]);
	output_as_coordinate(origin[2], vec_0[2], vec_1[2], vec_2[2]);
	// 3�Ԗ�
	mulMM4h(temporary_mat[1], temporary_mat[0], transform_mat[2]);
	mulMV4h(origin[3], temporary_mat[1], origin[0]);
	mulMV4h(vec_0[3], temporary_mat[1], vec_0[0]);
	mulMV4h(vec_1[3], temporary_mat[1], vec_1[0]);
	mulMV4h(vec_2[3], temporary_mat[1], vec_2[0]);
	output_as_coordinate(origin[3], vec_0[3], vec_1[3], vec_2[3]);
	// 4�Ԗ�
	mulMM4h(temporary_mat[2], temporary_mat[1], transform_mat[3]);
	mulMV4h(origin[4], temporary_mat[2], origin[0]);
	mulMV4h(vec_0[4], temporary_mat[2], vec_0[0]);
	mulMV4h(vec_1[4], temporary_mat[2], vec_1[0]);
	mulMV4h(vec_2[4], temporary_mat[2], vec_2[0]);
	output_as_coordinate(origin[4], vec_0[4], vec_1[4], vec_2[4]);
	// 5�Ԗ�
	mulMM4h(temporary_mat[3], temporary_mat[2], transform_mat[4]);
	mulMV4h(origin[5], temporary_mat[3], origin[0]);
	mulMV4h(vec_0[5], temporary_mat[3], vec_0[0]);
	mulMV4h(vec_1[5], temporary_mat[3], vec_1[0]);
	mulMV4h(vec_2[5], temporary_mat[3], vec_2[0]);
	output_as_coordinate(origin[5], vec_0[5], vec_1[5], vec_2[5]);
	// 6�Ԗ�
	mulMM4h(temporary_mat[4], temporary_mat[3], transform_mat[5]);
	mulMV4h(origin[6], temporary_mat[4], origin[0]);
	mulMV4h(vec_0[6], temporary_mat[4], vec_0[0]);
	mulMV4h(vec_1[6], temporary_mat[4], vec_1[0]);
	mulMV4h(vec_2[6], temporary_mat[4], vec_2[0]);
	output_as_coordinate(origin[6], vec_0[6], vec_1[6], vec_2[6]);
	// 7�Ԗ�
	mulMM4h(temporary_mat[5], temporary_mat[4], transform_mat[6]);
	mulMV4h(origin[7], temporary_mat[5], origin[0]);
	mulMV4h(vec_0[7], temporary_mat[5], vec_0[0]);
	mulMV4h(vec_1[7], temporary_mat[5], vec_1[0]);
	mulMV4h(vec_2[7], temporary_mat[5], vec_2[0]);
	output_as_coordinate(origin[7], vec_0[7], vec_1[7], vec_2[7]);
	// 8�Ԗ�
	mulMM4h(temporary_mat[6], temporary_mat[5], transform_mat[7]);
	mulMV4h(origin[8], temporary_mat[6], origin[0]);
	mulMV4h(vec_0[8], temporary_mat[6], vec_0[0]);
	mulMV4h(vec_1[8], temporary_mat[6], vec_1[0]);
	mulMV4h(vec_2[8], temporary_mat[6], vec_2[0]);
	output_as_coordinate(origin[8], vec_0[8], vec_1[8], vec_2[8]);


	//3�p�����W�w��p�z��
	double link_1[TRIPRISM_V_NUM][DIM];
	double link_2[TRIPRISM_V_NUM][DIM];
	double link_3[TRIPRISM_V_NUM][DIM];
	double pre_link_2[TRIPRISM_V_NUM][DIM];
	double pre_link_3[TRIPRISM_V_NUM][DIM];

	double transed_link_1[TRIPRISM_V_NUM][DIM];
	double transed_link_2[TRIPRISM_V_NUM][DIM];
	double transed_link_3[TRIPRISM_V_NUM][DIM];
	set_triprism(link_1, 3);
	set_triprism(pre_link_2, 2);
	set_triprism(pre_link_3, 1);

	// �A�[���̏������W��ϊ�����s��
	double rotate_link[VECTOR_LEN][VECTOR_LEN];
	unitMat4h(rotate_link);
	rotateX4h(rotate_link, -90*3.14/180.0);
	// link2��link3�̏������W��ϊ�
	for (int i = 0; i < TRIPRISM_V_NUM; i++)
	{
		mulMV4h(link_2[i], rotate_link, pre_link_2[i]);
		mulMV4h(link_3[i], rotate_link, pre_link_3[i]);
		printVec(link_2[i]);
	}

	// �ϊ��s���p���ĎO�p����ϊ�
	for (int i = 0; i < TRIPRISM_V_NUM; i++)
	{
		mulMV4h(transed_link_1[i], transform_mat[0], link_1[i]);
	}
	for (int i = 0; i < TRIPRISM_V_NUM; i++)
	{
		mulMV4h(transed_link_2[i], temporary_mat[2], link_2[i]);
	}
	for (int i = 0; i < TRIPRISM_V_NUM; i++)
	{
		mulMV4h(transed_link_3[i], temporary_mat[5], link_3[i]);
	}

	FILE *outputfile;
	outputfile = fopen("arm.stl", "w");
	if (outputfile == NULL)
	{
		printf("cannot open [arm.stl]\n");
	}
	prStlTriprism2file(transed_link_1, "link_1", outputfile);
	prStlTriprism2file(transed_link_2, "link_2", outputfile);
	prStlTriprism2file(transed_link_3, "link_3", outputfile);
	fclose(outputfile);
	//gnuplot�Ƀv���b�g
	//plot2gnuplot();
}

void kadai2B_run()
{
	//kadai2B_1();
	//kadai2B_2();
	kadai2B_3();
}
