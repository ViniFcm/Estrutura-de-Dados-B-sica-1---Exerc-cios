/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <utility>

using namespace std;

/**
 * @brief Conta o número de elementos pares e ímpares em um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 * @return Um par onde o primeiro valor é o número de elementos pares e o segundo é o número de elementos ímpares.
 */
std::pair<int, int> contarParesImpares(const int numeros[], int tamanho) {
    int pares = 0;
    int impares = 0;
    return make_pair(pares, impares);
}

TEST_CASE("Contar Pares e Ímpares - Teste com elementos mistos") {
    int numeros[] = {1, 2, 3, 4, 5, 6};
    auto resultado = contarParesImpares(numeros, 6);
    CHECK(resultado.first == 3);   // Pares
    CHECK(resultado.second == 3);  // Ímpares
}

TEST_CASE("Contar Pares e Ímpares - Teste com todos pares") {
    int numeros[] = {2, 4, 6, 8};
    auto resultado = contarParesImpares(numeros, 4);
    CHECK(resultado.first == 4);
    CHECK(resultado.second == 0);
}

TEST_CASE("Contar Pares e Ímpares - Teste com todos ímpares") {
    int numeros[] = {1, 3, 5, 7};
    auto resultado = contarParesImpares(numeros, 4);
    CHECK(resultado.first == 0);
    CHECK(resultado.second == 4);
}

TEST_CASE("Contar Pares e Ímpares - Teste com array vazio") {
    // Em vez de usar um array de tamanho zero, tratamos o caso vazio explicitamente
    CHECK(contarParesImpares(nullptr, 0) == std::make_pair(0, 0));
}
