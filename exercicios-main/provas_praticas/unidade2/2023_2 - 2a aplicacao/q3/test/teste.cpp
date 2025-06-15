#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ListaEncadeada.h"
#include <iostream>

using namespace Catch::Matchers;

TEST_CASE("Inverter - Lista vazia") 
{
    ListaEncadeada lista;

    lista.inverter();

    std::string resultadoEsperado = "null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Inverter - Lista com um só elemento") 
{
    ListaEncadeada lista;

    lista.inserirNoInicio(1);

    lista.inverter();

    std::string resultadoEsperado = "1->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}

TEST_CASE("Inverter - Lista com elementos") 
{
    ListaEncadeada lista;

    int v1[] = {10, 8, 6, 4, 2, 0};
                        
    for(auto s : v1) lista.inserirNoInicio( s );

    lista.inverter();

    std::string resultadoEsperado = "10->8->6->4->2->0->null";
    std::string resultadoRecebido = lista.imprimir();

    REQUIRE_THAT( resultadoRecebido, Equals(resultadoEsperado) );
}
