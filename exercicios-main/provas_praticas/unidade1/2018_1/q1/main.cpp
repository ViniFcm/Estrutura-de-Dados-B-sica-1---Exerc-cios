#include "Search.h"
#include <cassert>
#include <iostream>
int main(void)
{
	int v1[] = {0, 1, 1, 3, 4, 4, 4, 4, 5, 6, 7, 8, 8, 8, 8, 8, 9, 10, 10, 10 };
	int size1 = sizeof(v1)/sizeof(int);

	assert( findRightmost(v1, size1,  0) == 0);
	assert( findRightmost(v1, size1,  4) == 7);
	assert( findRightmost(v1, size1,  7) == 10);
	assert( findRightmost(v1, size1, 10) == size1-1);
	assert( findRightmost(v1, size1, -1) == -1);
	assert( findRightmost(v1, size1,  2) == -1);
	assert( findRightmost(v1, size1, 11) == -1);

	std::cout << "Q1 - Passou em todos os testes!" << std::endl;
	return 0;
}
