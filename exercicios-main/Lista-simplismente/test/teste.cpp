#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Lista.h"
#include <string>
#include <stdexcept>

TEST_CASE("Estado inicial da lista") {
    Lista lista;
    CHECK(lista.tamanho() == 0);
    CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
    CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
}

TEST_CASE("Inserção no início com S, P, F, C") {
    Lista lista;

    lista.inserirInicio("C");
    CHECK(lista.tamanho() == 1);
    CHECK(lista.primeiroElemento() == "C");
    CHECK(lista.ultimoElemento() == "C");

    lista.inserirInicio("F");
    CHECK(lista.tamanho() == 2);
    CHECK(lista.primeiroElemento() == "F");
    CHECK(lista.ultimoElemento() == "C");

    lista.inserirInicio("P");
    CHECK(lista.tamanho() == 3);
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "C");

    lista.inserirInicio("S");
    CHECK(lista.tamanho() == 4);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "C");
}

TEST_CASE("Inserção no fim com S, P, F, C") {
    Lista lista;

    lista.inserirFim("S");
    CHECK(lista.tamanho() == 1);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "S");

    lista.inserirFim("P");
    CHECK(lista.tamanho() == 2);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "P");

    lista.inserirFim("F");
    CHECK(lista.tamanho() == 3);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "F");

    lista.inserirFim("C");
    CHECK(lista.tamanho() == 4);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "C");
}

TEST_CASE("Remoção no início após inserir S, P, F, C") {
    Lista lista;
    lista.inserirFim("S");
    lista.inserirFim("P");
    lista.inserirFim("F");
    lista.inserirFim("C");

    CHECK(lista.removerInicio() == true);
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "C");
    CHECK(lista.tamanho() == 3);

    CHECK(lista.removerInicio() == true);
    CHECK(lista.primeiroElemento() == "F");
    CHECK(lista.ultimoElemento() == "C");
    CHECK(lista.tamanho() == 2);

    CHECK(lista.removerInicio() == true);
    CHECK(lista.primeiroElemento() == "C");
    CHECK(lista.ultimoElemento() == "C");
    CHECK(lista.tamanho() == 1);

    CHECK(lista.removerInicio() == true);
    CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
    CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
    CHECK(lista.tamanho() == 0);
}

TEST_CASE("Remoção no fim após inserir S, P, F, C") {
    Lista lista;
    lista.inserirFim("S");
    lista.inserirFim("P");
    lista.inserirFim("F");
    lista.inserirFim("C");

    CHECK(lista.removerFim() == true);
    CHECK(lista.ultimoElemento() == "F");
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.tamanho() == 3);

    CHECK(lista.removerFim() == true);
    CHECK(lista.ultimoElemento() == "P");
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.tamanho() == 2);

    CHECK(lista.removerFim() == true);
    CHECK(lista.ultimoElemento() == "S");
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.tamanho() == 1);

    CHECK(lista.removerFim() == true);
    CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
    CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);
    CHECK(lista.tamanho() == 0);
}

TEST_CASE("Remoção em lista vazia") {
    Lista lista;
    CHECK_THROWS_AS(lista.removerInicio(), std::out_of_range);
    CHECK_THROWS_AS(lista.removerFim(), std::out_of_range);
}

TEST_CASE("Inserção na i-ésima posição") {
    Lista lista;

    CHECK(lista.inserirNaPosicao(1, "S") == true); // início
    CHECK(lista.inserirNaPosicao(2, "C") == true); // fim
    CHECK(lista.inserirNaPosicao(2, "P") == true); // meio
    CHECK(lista.inserirNaPosicao(3, "F") == true); // meio

    CHECK(lista.tamanho() == 4);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "C");

    CHECK(lista.inserirNaPosicao(5, "!") == true); // fim
    CHECK(lista.tamanho() == 5);
    CHECK(lista.primeiroElemento() == "S");
    CHECK(lista.ultimoElemento() == "!");

    CHECK_THROWS_AS(lista.inserirNaPosicao(-1, "X"), std::out_of_range);
    CHECK_THROWS_AS(lista.inserirNaPosicao( 0, "X"), std::out_of_range);
    CHECK_THROWS_AS(lista.inserirNaPosicao( lista.tamanho()+2, "X"), std::out_of_range);
    CHECK_THROWS_AS(lista.inserirNaPosicao( lista.tamanho()+3, "X"), std::out_of_range);
}

TEST_CASE("Remoção na i-ésima posição") {
    Lista lista;
    lista.inserirFim("S");
    lista.inserirFim("P");
    lista.inserirFim("F");
    lista.inserirFim("C");
    lista.inserirFim("!");
    // conteúdo da lista é: SPFC!

    CHECK(lista.tamanho() == 5);

    CHECK(lista.removerNaPosicao(1) == true); // remove "S", permanece PFC!
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "!");
    CHECK(lista.tamanho() == 4);

    CHECK(lista.removerNaPosicao(4) == true); // remove "!", permanece PFC
    CHECK(lista.tamanho() == 3);
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "C");

    CHECK(lista.removerNaPosicao(2) == true); // remove "F", permanece PC
    CHECK(lista.tamanho() == 2);
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "C");

    CHECK(lista.removerNaPosicao(2) == true); // remove "C", permanece P
    CHECK(lista.tamanho() == 1);
    CHECK(lista.primeiroElemento() == "P");
    CHECK(lista.ultimoElemento() == "P");

    CHECK(lista.removerNaPosicao(1) == true);  // remove "P", fica vazia
    CHECK(lista.tamanho() == 0);
    CHECK_THROWS_AS(lista.primeiroElemento(), std::out_of_range);
    CHECK_THROWS_AS(lista.ultimoElemento(), std::out_of_range);

    CHECK_THROWS_AS(lista.removerNaPosicao(-1), std::out_of_range);
    CHECK_THROWS_AS(lista.removerNaPosicao( 0), std::out_of_range);
    CHECK_THROWS_AS(lista.removerNaPosicao(lista.tamanho()+1), std::out_of_range);
    CHECK_THROWS_AS(lista.removerNaPosicao(lista.tamanho()+2), std::out_of_range);
}

TEST_CASE("Acesso à i-ésima posição") {
    Lista lista;
    lista.inserirFim("S");
    lista.inserirFim("P");
    lista.inserirFim("F");
    lista.inserirFim("C");
    lista.inserirFim("!");

    CHECK_NOTHROW(lista.elementoNaPosicao(1));
    CHECK(lista.elementoNaPosicao(1) == "S");

    CHECK_NOTHROW(lista.elementoNaPosicao(2));
    CHECK(lista.elementoNaPosicao(2) == "P");

    CHECK_NOTHROW(lista.elementoNaPosicao(3));
    CHECK(lista.elementoNaPosicao(3) == "F");

    CHECK_NOTHROW(lista.elementoNaPosicao(4));
    CHECK(lista.elementoNaPosicao(4) == "C");

    CHECK_NOTHROW(lista.elementoNaPosicao(5));
    CHECK(lista.elementoNaPosicao(5) == "!");

    CHECK_THROWS_AS(lista.elementoNaPosicao(-1), std::out_of_range);
    CHECK_THROWS_AS(lista.elementoNaPosicao( 0), std::out_of_range);
    CHECK_THROWS_AS(lista.elementoNaPosicao(lista.tamanho()+1), std::out_of_range);
    CHECK_THROWS_AS(lista.elementoNaPosicao(lista.tamanho()+2), std::out_of_range);
}
