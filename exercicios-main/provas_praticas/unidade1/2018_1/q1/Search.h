#include <string>

using namespace std;

/**
	Função de busca pela posição mais a direita de uma determinada chave.

	@param v - array de entrada já ordenado em ordem crescente
	@param size - tamanho do array de entrada
	@param key - valor do elemento que se está procurando

	@return 
	Esta função retorna o índice i tal que v[i] == key. 
	Em caso de repetições no array de entrada, deve-se retornar o índice do elemento mais à direita.
	Caso não se encontre a chave no array de entrada, deve-se retornar -1.
*/
int findRightmost(int v[], int size, int key);
