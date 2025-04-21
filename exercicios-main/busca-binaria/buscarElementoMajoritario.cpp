/**
 * @file buscarElementoMajoritario.cpp
 * @brief Determina se existe um elemento majoritário em um array ordenado.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Verifica se existe um elemento majoritário em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @return O elemento majoritário se existir, caso contrário -1.
 */
int buscarElementoMajoritario(const int arr[], int tamanho) {
    return -1;
}

TEST_CASE("Buscar o Elemento Majoritário - Testes") {
    int arr1[] = {1, 1, 1, 2, 2, 2, 2};
    CHECK(buscarElementoMajoritario(arr1, 7) == 2);
    
    int arr2[] = {1, 2, 3, 4, 5};
    CHECK(buscarElementoMajoritario(arr2, 5) == -1);
    
    int arr3[] = {3, 3, 3, 3, 4};
    CHECK(buscarElementoMajoritario(arr3, 5) == 3);
    
    int arr4[] = {10, 10, 10, 10, 10, 11, 12};
    CHECK(buscarElementoMajoritario(arr4, 7) == 10);
}
