#include "../include/kadai1A.h"

int kadai1A_run()
{
	double vec0[VECTOR_LEN];
	double vec1[VECTOR_LEN];
	double vec2[VECTOR_LEN];
	double vec3[VECTOR_LEN];

	printf("vec0 : \n");
	setVec4h(vec0, 1, 1, 1);
	printVec(vec0);

	printf("vec1 : \n");
	setVec4h(vec1, 1, 1, -1);
	printVec(vec1);

	printf("---------------------------------\n");

	printf("length vec0 : %lf\n", length4h(vec0));
	printf("length vec1 : %lf\n", length4h(vec1));

	printf("---------------------------------\n");

	printf("Normalized : \n");
	double normalizedVec0[VECTOR_LEN];
	setVec4h(normalizedVec0, 0, 0, 0);
	printVec(vec0);
	normalize4h(normalizedVec0, vec0);
	printf("->");
	printVec(normalizedVec0);

	printf("---------------------------------\n");

	printf("Negative : \n");
	double negativeVec0[VECTOR_LEN];
	setVec4h(negativeVec0, 0, 0, 0);
	negate4h(negativeVec0, vec0);
	printVec(vec0);
	printf("->\n");
	printVec(negativeVec0);

	printf("---------------------------------\n");

	printf("Scaled : \n");
	double scaledVec0[VECTOR_LEN];
	double scale_factor = 2.0;
	setVec4h(scaledVec0, 0, 0, 0);
	scaleVec4h(scaledVec0, 2, vec0);
	printVec(vec0);
	printf(" * %lf -> \n", scale_factor);
	printVec(scaledVec0);

	printf("---------------------------------\n");

	printf("add : \n");
	double addVec0[VECTOR_LEN];
	setVec4h(addVec0, 0, 0, 0);
	setVec4h(vec0, 1, 2, 0);
	setVec4h(vec1, 0, 1, -1);
	printVec(vec0); printf("+"); printVec(vec1); printf("=");
	add4h(addVec0, vec0, vec1);
	printVec(addVec0);

	printf("---------------------------------\n");

	printf("sub : \n");
	double subVec0[VECTOR_LEN];
	setVec4h(subVec0, 0, 0, 0);
	setVec4h(vec0, 1, 2, 0);
	setVec4h(vec1, 0, 1, -1);
	printVec(vec0); printf("-"); printVec(vec1); printf("=");
	sub4h(subVec0, vec0, vec1);
	printVec(subVec0);

	printf("---------------------------------\n");

	printf("dot : \n");
	setVec4h(vec0, 1, 2, 3);
	setVec4h(vec1, 4, 5, 6);
	printVec(vec0); printf(" * "); printVec(vec1); printf("=");
	printf("%lf\n", dot4h(vec0, vec1));

	printf("---------------------------------\n");

	printf("cross : \n");
	double crossVec0[VECTOR_LEN];
	setVec4h(vec0, 1, 2, 0);
	setVec4h(vec1, 0, 1, -1);
	cross4h(crossVec0, vec0, vec1);
	printVec(vec0); printf(" * "); printVec(vec1); printf("=");
	printVec(crossVec0);

	printf("---------------------------------\n");

	printf("angle : \n");
	setVec4h(vec0, 1, 2, 0);
	setVec4h(vec1, 0, 1, -1);
	printf("vec0 : \n"); printVec(vec0);
	printf("vec1 : \n"); printVec(vec1);
	printf("angle0 = %lf\n", angle4h(vec0, vec1));

	printf("---------------------------------\n");

	printf("asDirVec0 : \n");
	asDirVec4h(vec0);
	printVec(vec0);
	printf("asDirVec1 : \n");
	asDirVec4h(vec1);
	printVec(vec1);

	printf("---------------------------------\n");

	printf("asPosVec0 : \n");
	asPosVec4h(vec0);
	printVec(vec0);
	printf("asPosVec1 : \n");
	asPosVec4h(vec1);
	printVec(vec1);

	printf("---------------------------------\n");
	printf("mulMM4h()\n");
	double mat0[VECTOR_LEN][VECTOR_LEN];
	double mat1[VECTOR_LEN][VECTOR_LEN];
	double mat2[VECTOR_LEN][VECTOR_LEN];
	setVec4h(vec0, 1, 2, 1);
	setVec4h(vec1, 2, 1, 1);
	setVec4h(vec2, 1, 0, 2);
	setVec4h(vec3, 4, 5, 6);
	asDirVec4h(vec0);
	asDirVec4h(vec1);
	asDirVec4h(vec2);
	setMatCol4h(mat0, vec0, vec1, vec2, vec3);
	setMatCol4h(mat1, vec2, vec1, vec0, vec3);
	mulMM4h(mat2, mat0, mat1);
	printf("mat0 =\n");
	printMat(mat0);
	printf("mat1 =\n");
	printMat(mat1);
	printf("mat2 =\n");
	printMat(mat2);

	printf("---------------------------------\n");
	printf("mulMV4h()\n");
	mulMV4h(vec0, mat0, vec1);
	printVec(vec0); printf(" = \n");
	printMat(mat0); printf(" * \n");
	printVec(vec1);

	printf("---------------------------------\n");
	printf("invMat4h()\n");
	double inv_mat0[VECTOR_LEN][VECTOR_LEN];
	invMat4h(inv_mat0, mat0);
	printf("mat0 = \n");
	printMat(mat0);
	printf("inv_mat0 = \n");
	printMat(inv_mat0);
	printf("mat0 * inv_mat0 = \n");
	double mat_x_invmat[VECTOR_LEN][VECTOR_LEN];
	mulMM4h(mat_x_invmat, mat0, inv_mat0);
	printMat(mat_x_invmat);

	return 0;
}
