#include "catch_amalgamated.hpp"
#include "TabelaHash.h"
#include <iostream>

using namespace std;

TEST_CASE("Tabela Hash - Teste de Inserir Simples") 
{    
    TabelaHash tabela;

    string chave = string("CHAVE");
    string valor = string("VALOR");

    auto quantidadeAntes = tabela.getQuantidade();
    bool inseriu = tabela.inserir(chave, valor);
    auto quantidadeDepois = tabela.getQuantidade();

    CHECK(inseriu);
    CHECK(quantidadeAntes+1 == quantidadeDepois);
    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Vários Seguidos") 
{
    std::size_t tamanhoInicial = 1379;
    
    TabelaHash tabela(tamanhoInicial);

    for(std::size_t i = 0; i < tamanhoInicial; ++i)
    {
        auto chave = string("CHAVE-" + std::to_string(i));
        auto valor = string("VALOR-" + std::to_string(i));
        tabela.inserir(chave, valor);
    }

    CHECK(tabela.getQuantidade() == tamanhoInicial);
    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Atualização") 
{    
    TabelaHash tabela;

    string chave1 = "abcd";
    string valor1 = "VALOR1";

    string chave2 = "dabc";
    string valor2 = "VALOR2";

    string novoValor2 = "NOVO";

    auto indice1 = tabela.hash(chave1);
    auto indice2 = tabela.hash(chave2);

    REQUIRE(indice1 == indice2);

    tabela.inserir(chave1, valor1);
    tabela.inserir(chave2, valor2);

    tabela.inserir(chave2, novoValor2);

    CHECK(tabela.array[indice2+1]->getValor() == novoValor2);

    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir após REMOVIDO") 
{    
    TabelaHash tabela;

    string chaveBase = "abcde";

    auto indice = tabela.hash(chaveBase);

    tabela.array[indice+0] = new Par<string, string>("abcde", "VALOR1");
    tabela.array[indice+1] = new Par<string, string>("eabcd", "VALOR2");
    tabela.array[indice+2] = REMOVIDO;
    tabela.array[indice+3] = new Par<string, string>("deabc", "VALOR3");
    tabela.array[indice+4] = new Par<string, string>("cdeab", "VALOR4");

    string chaveNova = "bcdea";
    string valorNovo = "NovoValor";
    
    tabela.inserir(chaveNova, valorNovo);

    REQUIRE( tabela.array[indice+2] != REMOVIDO );

    CHECK( tabela.array[indice+2]->getChave() == chaveNova);
    CHECK( tabela.array[indice+2]->getValor() == valorNovo);

    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Atualizar após REMOVIDO") 
{    
    TabelaHash tabela;

    string chaveBase = "abcde";

    auto indice = tabela.hash(chaveBase);

    tabela.array[indice+0] = new Par<string, string>("abcde", "VALOR1");
    tabela.array[indice+1] = new Par<string, string>("eabcd", "VALOR2");
    tabela.array[indice+2] = REMOVIDO;
    tabela.array[indice+3] = new Par<string, string>("deabc", "VALOR3");
    tabela.array[indice+4] = new Par<string, string>("cdeab", "VALOR4");

    string chaveNova = "cdeab";
    string valorNovo = "NovoValor";
    
    tabela.inserir(chaveNova, valorNovo);

    REQUIRE( tabela.array[indice+2] == REMOVIDO );

    CHECK( tabela.array[indice+4]->getChave() == chaveNova);
    CHECK( tabela.array[indice+4]->getValor() == valorNovo);

    CHECK_FALSE(tabela.possuiDuplicatas());
}
