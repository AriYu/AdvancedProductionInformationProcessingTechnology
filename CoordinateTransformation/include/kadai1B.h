#ifndef KADAI_1B_H_
#define KADAI_1B_H_

#include "base_vector.h"
#include "util.h"
#include "random_gen.h"

void set_arrow(double vs[][VECTOR_LEN]);
void set_base_coordinate(double origin[VECTOR_LEN], double vec0[VECTOR_LEN], double vec1[VECTOR_LEN], double vec2[VECTOR_LEN]);
void set_random_coordinate(double origin[VECTOR_LEN], double vec0[VECTOR_LEN], double vec1[VECTOR_LEN], double vec2[VECTOR_LEN]);
int kadai1B_run();

#endif