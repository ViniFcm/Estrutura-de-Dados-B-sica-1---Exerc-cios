#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int findBase(vector<int> v, int left, int right)
{
	return -1;
}

int testCounter = 0;

void test(vector<int> v, int expectedIndex)
{
	std::cout << "\tINÍCIO: Teste " << ++testCounter << endl;	
	
	int r = findBase(v, 0, v.size()-1);

	std::cout << "Entrada: (abaixo, impressos índice:valor)\n\t{" << std::endl;

	int counter = 0;
	for( int i : v )
		std::cout << counter++ << ":" << i << ", ";
	std::cout << "}\n";	

	
	std::cout << "\nSaída:" << std::endl;
	if( v[r] != v[expectedIndex] )
		std::cout << "\tResultado esperado era " << expectedIndex << ", mas retornou " << r << endl;
	else
		std::cout << "\tResultado correto, índice esperado == retornado: " << r << endl;	

	std::cout << "\tFIM: Teste " << testCounter << endl << endl;	
}

int main(void)
{
	int s = 50;

	// entradas
	vector<int> v1(s), v2(s), v3(s);	
	for(int i = 0; i < s; i++)
	{
		v1[i] = i < s / 2 ? s-i : i; // decrescente + crescente
		v2[i] = i; // crescente
		v3[i] = s-i; // decrescente		
	}

	// testes
	test(v1, s/2); // v1 tem uma sequência inicial decrescente, depois outra sequência crescente
	test(v2, 0); // v2 tem uma sequência inicial decresente vazia, depois uma sequência crescente
	test(v3, s-1); // v3 tem uma sequência inicial descrescente, depois uma sequência crescente vazia

	return 0;
}
