/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Conta o número de elementos únicos em um array de inteiros.
 *
 * @param array O array de inteiros.
 * @param tamanho O tamanho do array.
 * @return O número de elementos únicos no array.
 */
int contarElementosUnicos(const int numeros[], int tamanho) {
    return -1;
}

TEST_CASE("Contar Elementos Únicos - Teste com elementos únicos") {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);
    CHECK(contarElementosUnicos(array, tamanho) == 5);
}

TEST_CASE("Contar Elementos Únicos - Teste com elementos repetidos") {
    int array[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int tamanho = sizeof(array) / sizeof(array[0]);
    CHECK(contarElementosUnicos(array, tamanho) == 4);
}

TEST_CASE("Contar Elementos Únicos - Teste com todos os elementos iguais") {
    int array[] = {7, 7, 7, 7};
    int tamanho = sizeof(array) / sizeof(array[0]);
    CHECK(contarElementosUnicos(array, tamanho) == 1);
}

TEST_CASE("Contar Elementos Únicos - Teste com array vazio") {
    int tamanho = 0;
    CHECK(contarElementosUnicos(nullptr, tamanho) == 0);
}

TEST_CASE("Contar Elementos Únicos - Teste com um único elemento") {
    int array[] = {42};
    int tamanho = sizeof(array) / sizeof(array[0]);
    CHECK(contarElementosUnicos(array, tamanho) == 1);
}
