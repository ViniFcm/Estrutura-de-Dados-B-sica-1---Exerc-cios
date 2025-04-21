/**
 * @file somaProdutoDigitos.cpp
 * @brief Calcula o somatório e o produtório dos dígitos de um número natural N usando recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <utility> // Para usar std::pair

/**
 * @brief Calcula o somatório e o produtório dos dígitos de um número natural N usando recursão.
 *
 * @param N O número natural a ser processado.
 * @return Um par com o somatório e o produtório dos dígitos de N.
 */
std::pair<int, int> somaProdutorioDigitos(int N) {
    return std::make_pair(-1, -1);
}

TEST_CASE("Soma e Produtório dos Dígitos - Testes") {
    auto resultado = somaProdutorioDigitos(0);
    CHECK(resultado.first == 0);  // Soma dos dígitos
    CHECK(resultado.second == 0); // Produtório dos dígitos

    resultado = somaProdutorioDigitos(9);
    CHECK(resultado.first == 9);  // Soma dos dígitos
    CHECK(resultado.second == 9); // Produtório dos dígitos

    resultado = somaProdutorioDigitos(1234);
    CHECK(resultado.first == 10);  // Soma: 1 + 2 + 3 + 4
    CHECK(resultado.second == 24); // Produtório: 1 * 2 * 3 * 4

    resultado = somaProdutorioDigitos(111111);
    CHECK(resultado.first == 6);   // Soma dos dígitos
    CHECK(resultado.second == 1);  // Produtório dos dígitos

    resultado = somaProdutorioDigitos(24680);
    CHECK(resultado.first == 20);  // Soma: 2 + 4 + 6 + 8 + 0
    CHECK(resultado.second == 0);  // Produtório: 2 * 4 * 6 * 8 * 0

    resultado = somaProdutorioDigitos(1764);
    CHECK(resultado.first == 1+7+6+4);  // Soma dos dígitos
    CHECK(resultado.second == 1*7*6*4); // Produtório dos dígitos

    resultado = somaProdutorioDigitos(1234567890);
    CHECK(resultado.first == 45);  // Soma dos dígitos
    CHECK(resultado.second == 0);  // Produtório dos dígitos

    resultado = somaProdutorioDigitos(987654321);
    CHECK(resultado.first == 45);  // Soma dos dígitos
    CHECK(resultado.second == 362880);  // Produtório dos dígitos
}
