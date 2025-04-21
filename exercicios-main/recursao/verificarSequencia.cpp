/**
 * @file verificarSequencia.cpp
 * @brief Verifica se existe uma sequência de pelo menos dois dígitos iguais e consecutivos em um número natural N usando recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Verifica se há dois dígitos iguais consecutivos em N usando recursão.
 *
 * @param N O número natural a ser verificado.
 * @return true se houver dois dígitos iguais consecutivos, false caso contrário.
 */
bool verificarSequencia(int N) {
    return false;
}

TEST_CASE("Verificar Dígitos Iguais Consecutivos - Testes") {
    CHECK(verificarSequencia(0) == false);
    CHECK(verificarSequencia(9) == false);
    CHECK(verificarSequencia(2113) == true);
    CHECK(verificarSequencia(2131) == false);
    CHECK(verificarSequencia(112345) == true);
    CHECK(verificarSequencia(123456) == false);
    CHECK(verificarSequencia(122233) == true);
}
