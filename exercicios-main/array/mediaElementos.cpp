/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <stdexcept>

/**
 * @brief Calcula a média dos elementos de um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return A média dos elementos do array.
 * @throws std::invalid_argument se o array estiver vazio.
 */
double mediaArray(const int numeros[], int tamanho) {
    return -1.0;
}

TEST_CASE("Média - Teste com elementos positivos") {
    int numeros[] = {1, 2, 3, 4, 5};
    CHECK(mediaArray(numeros, 5) == doctest::Approx(3.0).epsilon(1e-6));
}

TEST_CASE("Média - Teste com elementos negativos") {
    int numeros[] = {-1, -2, -3, -4, -5};
    CHECK(mediaArray(numeros, 5) == doctest::Approx(-3.0).epsilon(1e-6));
}

TEST_CASE("Média - Teste com array unitário") {
    int numeros[] = {100};
    CHECK(mediaArray(numeros, 1) == doctest::Approx(100.0).epsilon(1e-6));
}

TEST_CASE("Média - Teste com array vazio") {
    int numeros[] = {};
    CHECK_THROWS_AS(mediaArray(numeros, 0), std::invalid_argument);
}
