#include <cassert>
#include <iostream>

int divide(int a, int b)
{
	return -1;
}

int main(void)
{
	assert( divide(1000, 1000) == 1000/1000 );
	assert( divide(1000, 1) == 1000/1 );
	assert( divide(1000, 2) == 1000/2 );
	assert( divide(1000, 3) == 1000/3 );
	assert( divide(1000, 5) == 1000/5 );
	assert( divide(1000, 7) == 1000/7 );
	assert( divide(999, 47) == 999/47 );
	assert( divide(999, 1000) == 999/1000 );
	assert( divide(0, 999) == 0/999 );
	assert( divide(1, 999) == 1/999 );

	std::cout << "Q1_Divide - Passou em todos os testes!" << std::endl;
	return 0;
}
