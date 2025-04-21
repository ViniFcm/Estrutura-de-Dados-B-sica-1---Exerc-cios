/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <stdexcept>

/**
 * @brief Calcula a maior média móvel em um array de inteiros com uma janela de tamanho 4.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return A maior média móvel encontrada.
 * @throws std::invalid_argument se o tamanho do array for menor que 4.
 */
double maiorMediaMovel(const int numeros[], int tamanho) {
    return -1.0;
}

TEST_CASE("Maior Média Móvel - Teste com elementos positivos") {
    int numeros[] = {1, 2, 3, 4, 5};
    CHECK(maiorMediaMovel(numeros, 5) == doctest::Approx(3.5).epsilon(1e-6));
}

TEST_CASE("Maior Média Móvel - Teste com elementos mistos") {
    int numeros[] = {3, -2, 5, 1, 4};
    CHECK(maiorMediaMovel(numeros, 5) == doctest::Approx(2.0).epsilon(1e-6));
}

TEST_CASE("Maior Média Móvel - Teste com elementos negativos") {
    int numeros[] = {-1, -2, -3, -4, -5};
    CHECK(maiorMediaMovel(numeros, 5) == doctest::Approx(-2.5).epsilon(1e-6));
}

TEST_CASE("Maior Média Móvel - Teste com janela no limite") {
    int numeros[] = {10, 20, 30, 40};
    CHECK(maiorMediaMovel(numeros, 4) == doctest::Approx(25.0).epsilon(1e-6));
}

TEST_CASE("Maior Média Móvel - Teste com array muito pequeno") {
    int numeros[] = {1, 2, 3};
    CHECK_THROWS_AS(maiorMediaMovel(numeros, 3), std::invalid_argument);
}
