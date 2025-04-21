/**
 * @file buscaBinariaSimples.cpp
 * @brief Implementação da busca binária para encontrar um elemento em um array ordenado.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Realiza a busca binária em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O elemento a ser buscado.
 * @return O índice do elemento no array, ou -1 se não estiver presente.
 */
int buscaBinaria(const int arr[], int tamanho, int alvo) {
    return -1;
}

TEST_CASE("Busca Binária Simples - Testes") {
    int arr1[] = {1, 2, 3, 4, 5};
    CHECK(buscaBinaria(arr1, 5, 3) == 2);
    CHECK(buscaBinaria(arr1, 5, 5) == 4);
    CHECK(buscaBinaria(arr1, 5, 1) == 0);
    CHECK(buscaBinaria(arr1, 5, 6) == -1);
}
