/**
 * @file contarOcorrencias.cpp
 * @brief Conta o número de ocorrências de um elemento em um array ordenado usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Conta o número de ocorrências de um elemento em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O elemento a ser contado.
 * @return O número de ocorrências do elemento no array.
 */
int contarOcorrencias(const int arr[], int tamanho, int alvo) {
    return -1;
}

TEST_CASE("Contar Ocorrências de um Elemento em um Array Ordenado - Testes") {
    int arr1[] = {1, 2, 2, 2, 3, 4, 5};
    CHECK(contarOcorrencias(arr1, 7, 2) == 3);
    CHECK(contarOcorrencias(arr1, 7, 4) == 1);
    CHECK(contarOcorrencias(arr1, 7, 5) == 1);
    CHECK(contarOcorrencias(arr1, 7, 6) == 0);
}
