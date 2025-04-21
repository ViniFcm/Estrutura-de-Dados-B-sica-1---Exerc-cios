/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Encontra a posição onde um elemento deveria ser inserido em um array ordenado para mantê-lo ordenado.
 *
 * @param numeros Um array de inteiros ordenado. Considere que o array está em ordem crescente.
 * @param tamanho O tamanho do array.
 * @param elemento O elemento cuja posição deve ser encontrada.
 * @return A posição onde o elemento deveria estar.
 */
int posicaoInserirOrdenado(const int numeros[], int tamanho, int elemento) {
    return -1;
}

TEST_CASE("Posição Elemento Ordenado - Teste com elemento no meio") {
    int numeros[] = {1, 3, 5, 7};
    CHECK(posicaoInserirOrdenado(numeros, 4, 4) == 2);
}

TEST_CASE("Posição Elemento Ordenado - Teste com elemento menor") {
    int numeros[] = {1, 3, 5, 7};
    CHECK(posicaoInserirOrdenado(numeros, 4, 0) == 0);
}

TEST_CASE("Posição Elemento Ordenado - Teste com elemento maior") {
    int numeros[] = {1, 3, 5, 7};
    CHECK(posicaoInserirOrdenado(numeros, 4, 8) == 4);
}

TEST_CASE("Posição Elemento Ordenado - Teste com array vazio") {
    CHECK(posicaoInserirOrdenado(nullptr, 0, 10) == 0);
}
