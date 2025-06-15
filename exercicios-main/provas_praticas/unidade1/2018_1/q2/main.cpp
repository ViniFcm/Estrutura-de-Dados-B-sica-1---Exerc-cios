#include "Sum3.h"
#include <cassert>
#include <iostream>

int main(void)
{
	int v1[] = {0, 1, 1, 3, 4, 4, 4, 4, 5, 6, 7, 8, 8, 8, 8, 8, 9, 10, 10, 10 };
	int size1 = sizeof(v1)/sizeof(int);

	assert( existsSum3(v1, size1,  0) == true); //  0 == 0 + 0 + 0
	assert( existsSum3(v1, size1,  4) == true); //  4 == 0 + 1 + 3  || 0 + 0 + 4
	assert( existsSum3(v1, size1, 22) == true); // 22 == 4 + 8 + 10 || 5 + 7 + 10 || ...
	assert( existsSum3(v1, size1, 33) == false); 
	assert( existsSum3(v1, size1, -1) == false); 

	std::cout << "Q2 - Passou em todos os testes!" << std::endl;
	return 0;
}
