/**
 * @file encontrarPicoBitonico.cpp
 * @brief Encontra o ponto de pico em uma sequência bitônica usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Encontra um ponto de pico em uma sequência bitônica usando busca binária.
 *
 * @param arr O array de inteiros em ordem bitônica.
 * @param tamanho O tamanho do array.
 * @return O índice do ponto de pico.
 */
int encontrarPicoBitonico(const int arr[], int tamanho) {
    return -1;
}

TEST_CASE("Encontrar o Ponto de Pico em Sequência Bitônica - Testes") {
    int arr1[] = {1, 3, 8, 12, 4, 2}; // crescente e decrescente
    CHECK(encontrarPicoBitonico(arr1, 6) == 3);
    
    int arr2[] = {1, 2, 3, 4, 5}; // só crescente
    CHECK(encontrarPicoBitonico(arr2, 5) == 4); 
    
    int arr3[] = {50, 40, 30, 15}; // só decrescente
    CHECK(encontrarPicoBitonico(arr3, 4) == 0);
}
