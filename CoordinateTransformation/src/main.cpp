#define _CRT_SECURE_NO_DEPRECATE
#include "../include/base_vector.h"
#include "../include/util.h"

#include "../include/kadai1A.h"
#include "../include/kadai1B.h"
#include "../include/kadai2A.h"
#include "../include/kadai2B.h"

int main(void)
{
	renew_seed();

	//kadai1A_run();
	kadai1B_run();
	kadai2A_run();
	//kadai2B_run();

	return 0;
}