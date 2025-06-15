#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ListaEncadeada.h"
#include <iostream>

using namespace Catch::Matchers;

TEST_CASE("Rotacionar Lista - Lista vazia") 
{
    ListaEncadeada lista;

    lista.rotacionar(0);

    std::string resultadoEsperado = "null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
}

TEST_CASE("Rotacionar Lista - Lista com um só elemento") 
{
    ListaEncadeada lista;

    lista.inserirNoInicio(1);

    SECTION("Rotação de 0 elementos")
    {
        lista.rotacionar(0);

        std::string resultadoEsperado = "1->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }

    SECTION("Rotação de 1 elemento")
    {
        lista.rotacionar(1);

        std::string resultadoEsperado = "1->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }
}

TEST_CASE("Rotacionar Lista - Vários casos") 
{
    ListaEncadeada lista;

    int v1[] = {10, 8, 6, 4};
                        
    for(auto s : v1) lista.inserirNoInicio( s );

    SECTION("Rotação de 0 elementos")
    {
        lista.rotacionar(0);

        std::string resultadoEsperado = "4->6->8->10->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }

    SECTION("Rotação de 1 elemento")
    {
        lista.rotacionar(1);

        std::string resultadoEsperado = "10->4->6->8->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }

    SECTION("Rotação de 2 elementos")
    {
        lista.rotacionar(2);

        std::string resultadoEsperado = "8->10->4->6->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }

    SECTION("Rotação de 3 elementos")
    {
        lista.rotacionar(3);

        std::string resultadoEsperado = "6->8->10->4->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }
    
    SECTION("Rotação de 4 elementos")
    {
        lista.rotacionar(4);

        std::string resultadoEsperado = "4->6->8->10->null";
        std::string resultadoRecebido = lista.imprimir();

        REQUIRE_THAT(resultadoRecebido, Equals(resultadoEsperado));
    }
    
}

