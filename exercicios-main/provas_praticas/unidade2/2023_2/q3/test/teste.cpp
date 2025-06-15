#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ListaEncadeada.h"
#include <iostream>

TEST_CASE("Checagem de lista que é simétrica - tamanho ímpar") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"alpha", "bravo", "charlie", "bravo", "alpha"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    CHECK(lista.e_simetrica() == true);
}

TEST_CASE("Checagem de lista que é simétrica - tamanho par") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"alpha", "bravo", "charlie", "charlie", "bravo", "alpha"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    CHECK(lista.e_simetrica() == true);
}

TEST_CASE("Checagem de lista que não é simétrica - tamanho ímpar") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"eagle", "bravo", "charlie", "bravo", "alpha"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    CHECK(lista.e_simetrica() == false);
}

TEST_CASE("Checagem de lista que não é simétrica - tamanho par") 
{
    ListaEncadeada lista;
    
    std::string v1[] = {"alpha", "bravo", "charlie", "charlie", "eagle", "alpha"};
                      
    for(auto s : v1)
    {
        lista.inserirNoInicio( s );
    }

    CHECK(lista.e_simetrica() == false);
}

TEST_CASE("Checagem de lista vazia é simétrica") 
{
    ListaEncadeada lista;

    CHECK(lista.e_simetrica() == true);
}

TEST_CASE("Checagem de lista com um só elemento é simétrica") 
{
    ListaEncadeada lista;

    lista.inserirNoInicio("A");

    CHECK(lista.e_simetrica() == true);
}

