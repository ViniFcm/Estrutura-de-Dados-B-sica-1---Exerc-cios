#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ListaEncadeada.h"
#include <iostream>

using namespace Catch::Matchers;

TEST_CASE("Remover Repetidos - Lista vazia") 
{
    ListaEncadeada lista;

    int contagem = lista.removerRepetidos();

    std::string resultadoEsperado = "null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE( contagem == 0 );
    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Remover Repetidos - Lista com um só elemento") 
{
    ListaEncadeada lista;

    lista.inserirNoInicio(1);

    int contagem = lista.removerRepetidos();

    std::string resultadoEsperado = "1->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE( contagem == 0 );
    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Remover Repetidos - Lista sem elementos repetidos") 
{
    ListaEncadeada lista;

    int v1[] = {10, 8, 6, 4};
                        
    for(auto s : v1) lista.inserirNoInicio( s );

    int contagem = lista.removerRepetidos();

    std::string resultadoEsperado = "4->6->8->10->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE( contagem == 0 );
    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Remover Repetidos - Lista com elementos repetidos - Caso 1") 
{
    ListaEncadeada lista;

    int v1[] = {10, 10, 8, 6, 6, 6, 4};
                        
    for(auto s : v1) lista.inserirNoInicio( s );

    int contagem = lista.removerRepetidos();

    std::string resultadoEsperado = "4->6->8->10->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE( contagem == 3 );
    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Remover Repetidos - Lista com elementos repetidos - Caso 2") 
{
    ListaEncadeada lista;

    int v1[] = {10, 10, 8, 8, 6, 6, 4, 4};
                        
    for(auto s : v1) lista.inserirNoInicio( s );

    int contagem = lista.removerRepetidos();

    std::string resultadoEsperado = "4->6->8->10->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE( contagem == 4 );
    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}
