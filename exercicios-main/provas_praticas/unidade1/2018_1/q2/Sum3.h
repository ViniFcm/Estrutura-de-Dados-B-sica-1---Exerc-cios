#include <string>

using namespace std;

/**
	Função que verifica se é possível resolver o problema Soma3 no array de entrada.

	@param v - array de entrada já ordenado em ordem crescente
	@param size - tamanho do array de entrada
	@param sum - valor da soma que se deseja encontrar no array

	@return 
	Esta função retorna true caso existam índices i, j, k tais que v[i]+v[j]+v[k] == sum.
	Caso não existam tais índices, deve-se retornar false.
*/
bool existsSum3(int v[], int size, int sum);
