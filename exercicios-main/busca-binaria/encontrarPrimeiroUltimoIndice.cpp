/**
 * @file encontrarPrimeiroUltimoIndice.cpp
 * @brief Encontra o primeiro e o último índice de um elemento em um array ordenado.
 * 
 * (C) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <utility>  // Para usar std::pair

/**
 * @brief Encontra o primeiro e o último índice de um elemento no array usando busca binária.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O elemento a ser buscado.
 * @return Um par contendo o primeiro e o último índice do elemento encontrado, ou (-1, -1) se não estiver presente.
 */
std::pair<int, int> encontrarPrimeiroUltimoIndice(const int arr[], int tamanho, int alvo) {
    return std::make_pair(-1, -1);
}

TEST_CASE("Encontrar Primeiro e Último Índice - Testes") {
    int arr1[] = {1, 2, 2, 2, 3, 4, 5};

    auto resultado = encontrarPrimeiroUltimoIndice(arr1, 7, 2);
    CHECK(resultado.first == 1);
    CHECK(resultado.second == 3);

    resultado = encontrarPrimeiroUltimoIndice(arr1, 7, 4);
    CHECK(resultado.first == 5);
    CHECK(resultado.second == 5);

    resultado = encontrarPrimeiroUltimoIndice(arr1, 7, 5);
    CHECK(resultado.first == 6);
    CHECK(resultado.second == 6);

    resultado = encontrarPrimeiroUltimoIndice(arr1, 7, 6);
    CHECK(resultado.first == -1);
    CHECK(resultado.second == -1);

    resultado = encontrarPrimeiroUltimoIndice(arr1, 7, 1);
    CHECK(resultado.first == 0);
    CHECK(resultado.second == 0);
}
