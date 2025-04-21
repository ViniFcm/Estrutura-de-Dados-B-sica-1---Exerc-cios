/**
 * @file buscarMinimoArrayRotacionado.cpp
 * @brief Encontra o elemento mínimo em um array rotacionado usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Encontra o elemento mínimo em um array rotacionado usando busca binária.
 *
 * @param arr O array rotacionado de inteiros.
 * @param tamanho O tamanho do array.
 * @return O valor do elemento mínimo.
 */
int buscarMinimoArrayRotacionado(const int arr[], int tamanho) {
    return -1;
}

TEST_CASE("Buscar o Elemento Mínimo em um Array Rotacionado - Testes") {
    int arr1[] = {15, 22, 27, 30, 2, 5, 7};
    CHECK(buscarMinimoArrayRotacionado(arr1, 7) == 2);
    
    int arr2[] = {3, 4, 5, 1, 2};
    CHECK(buscarMinimoArrayRotacionado(arr2, 5) == 1);
    
    int arr3[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    CHECK(buscarMinimoArrayRotacionado(arr3, 9) == 1);
    
    int arr4[] = {1, 2, 3, 4, 5};
    CHECK(buscarMinimoArrayRotacionado(arr4, 5) == 1);
}
