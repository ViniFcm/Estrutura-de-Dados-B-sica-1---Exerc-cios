/**
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

/**
 * @brief Reverte a ordem dos elementos de um array de inteiros.
 *
 * @param numeros Um array de inteiros.
 * @param tamanho O tamanho do array.
 */
void reversaoArray(int numeros[], int tamanho) {
    return;
}

TEST_CASE("Reversão - Teste com elementos positivos") {
    int numeros[] = {1, 2, 3, 4, 5};
    reversaoArray(numeros, 5);
    CHECK(numeros[0] == 5);
    CHECK(numeros[1] == 4);
    CHECK(numeros[2] == 3);
    CHECK(numeros[3] == 2);
    CHECK(numeros[4] == 1);
}

TEST_CASE("Reversão - Teste com elementos negativos") {
    int numeros[] = {-1, -2, -3, -4, -5};
    reversaoArray(numeros, 5);
    CHECK(numeros[0] == -5);
    CHECK(numeros[1] == -4);
    CHECK(numeros[2] == -3);
    CHECK(numeros[3] == -2);
    CHECK(numeros[4] == -1);
}

TEST_CASE("Reversão - Teste com array unitário") {
    int numeros[] = {1};
    reversaoArray(numeros, 1);
    CHECK(numeros[0] == 1);
}

TEST_CASE("Reversão - Teste com array vazio") {
    reversaoArray(nullptr, 0);
}
