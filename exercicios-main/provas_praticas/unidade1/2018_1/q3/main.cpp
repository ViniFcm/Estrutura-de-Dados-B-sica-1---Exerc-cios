#include "Inversion.h"
#include <cassert>
#include <iostream>

int main(void)
{
	int v1[] = {0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
	assert( 25 == countInversions(v1, sizeof(v1)/sizeof(int)) );

	int v2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 100, 90};
	assert( 1 == countInversions(v2, sizeof(v2)/sizeof(int)) );

	int v3[] = {10, 11, 12, 90, 80, 70, 60, 50, 4, 3, 2};
	assert( 37 == countInversions(v3, sizeof(v3)/sizeof(int)) );

	int v4[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 100};
	assert( 0 == countInversions(v4, sizeof(v4)/sizeof(int)) );

	std::cout << "Q3 - Passou em todos os testes!" << std::endl;

	return 0;
}
