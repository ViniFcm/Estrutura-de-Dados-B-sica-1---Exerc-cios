#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ListaEncadeada.h"
#include <iostream>

TEST_CASE("Remoção de uma lista vazia") 
{
    ListaEncadeada lista;
    
    auto tamanhoAntes = lista.tamanho();

    CHECK( lista.remover( "VALOR_QUE_NAO_TEM_NA_LISTA" ) == false );

    auto tamanhoDepois = lista.tamanho();

    CHECK( tamanhoAntes == tamanhoDepois );
}

TEST_CASE("Remoção de uma lista com um só elemento") 
{
    ListaEncadeada lista;

    lista.inserirNoInicio("alpha");
    
    CHECK( lista.remover( "VALOR_QUE_NAO_TEM_NA_LISTA" ) == false );
    CHECK( lista.getInicio() != nullptr );
    CHECK( lista.remover( "alpha" ) == true );
    CHECK( lista.getInicio() == nullptr );
}

TEST_CASE("Remoção de elementos que estão na lista") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"golf", "charlie", "alpha", "delta", "echo", "bravo", "fox", "india", "hotel", "juliet",
                        "alpha", "echo", "bravo", "delta", "golf", "charlie", "juliet", "fox", "india", "hotel"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    for(auto s : v1)
    {
        auto tamanhoAntes = lista.tamanho();

        bool removeu = lista.remover( s );

        auto tamanhoDepois = lista.tamanho();

        CHECK( tamanhoAntes == tamanhoDepois + 1 );
        CHECK( removeu == true );
    }
}

TEST_CASE("Remoção de elementos que não estão na lista") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"golf", "charlie", "alpha", "delta", "echo", "bravo", "fox", "india", "hotel", "juliet",
                        "alpha", "echo", "bravo", "delta", "golf", "charlie", "juliet", "fox", "india", "hotel"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    for(int i = 0; i < 10; i++)
    {
        auto tamanhoAntes = lista.tamanho();

        bool removeu = lista.remover( "VALOR_QUE_NAO_TEM_NA_LISTA" );

        auto tamanhoDepois = lista.tamanho();

        CHECK( tamanhoAntes == tamanhoDepois );
        CHECK( removeu == false );
    }
}

