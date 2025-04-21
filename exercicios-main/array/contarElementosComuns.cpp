/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Conta o número de elementos comuns entre dois arrays de inteiros.
 *
 * @param array1 O primeiro array de inteiros.
 * @param tamanho1 O tamanho do primeiro array.
 * @param array2 O segundo array de inteiros.
 * @param tamanho2 O tamanho do segundo array.
 * @return O número de elementos comuns entre os dois arrays.
 */
int contarElementosComuns(const int array1[], int tamanho1, const int array2[], int tamanho2) {
    return -1;
}

TEST_CASE("Contar Elementos Comuns - Teste com arrays com elementos comuns") {
    int array1[] = {1, 2, 3, 4};
    int array2[] = {3, 4, 5, 6};
    CHECK(contarElementosComuns(array1, 4, array2, 4) == 2);
}

TEST_CASE("Contar Elementos Comuns - Teste com arrays sem elementos comuns") {
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    CHECK(contarElementosComuns(array1, 3, array2, 3) == 0);
}

TEST_CASE("Contar Elementos Comuns - Teste com arrays iguais") {
    int array1[] = {1, 2, 3};
    int array2[] = {1, 2, 3};
    CHECK(contarElementosComuns(array1, 3, array2, 3) == 3);
}

TEST_CASE("Contar Elementos Comuns - Teste com um array vazio") {
    int array1[] = {1, 2, 3};
    CHECK(contarElementosComuns(array1, 3, nullptr, 0) == 0);
}

TEST_CASE("Contar Elementos Comuns - Teste com o outro array vazio") {
    int array2[] = {1, 2, 3};
    CHECK(contarElementosComuns(nullptr, 0, array2, 3) == 0);
}