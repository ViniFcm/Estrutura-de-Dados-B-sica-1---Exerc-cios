/**
 * @file multiplicacaoRecursiva.cpp
 * @brief Multiplicar dois números inteiros usando adições sucessivas e recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Multiplica dois números inteiros X e Y usando adições sucessivas e recursão.
 *
 * @param X O primeiro número a ser multiplicado.
 * @param Y O segundo número a ser multiplicado.
 * @return O resultado da multiplicação de X e Y.
 */
int multiplicacao(int X, int Y) {
    return -1;
}

TEST_CASE("Multiplicar Dois Números Inteiros - Testes") {
    CHECK(multiplicacao(3, 4) == 12);
    CHECK(multiplicacao(0, 5) == 0);
    CHECK(multiplicacao(5, 0) == 0);
    CHECK(multiplicacao(-3, 2) == -6);
    CHECK(multiplicacao(7, -3) == -21);
}
