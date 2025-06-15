#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"
#include <iostream>

bool contemChave(Par<std::string, std::string>*& pPar, std::string chave)
{
    auto aux = pPar;
    while(aux!=nullptr)
    {
        if(aux->getChave() == chave)
        {
            return true;
        }
        else
        {
            aux = aux->getProximo();
        }
    }

    return false;
}

TEST_CASE("Tabela Hash - Teste de Inserir Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = std::string("CHAVE");
    std::string valor = std::string("VALOR");

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
        auto chave = std::string("CHAVE-" + std::to_string(i));
        auto valor = std::string("VALOR-" + std::to_string(i));
        tabela.inserir(chave, valor);
    }

    CHECK(tabela.getQuantidade() == tamanhoInicial);
    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Atualização") 
{
    std::size_t tamanhoInicial = 13;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE1";
    std::string valor1 = "VALOR1";
    std::string novoValor = "NOVO";

    auto indice = tabela.hash(chave1);

    tabela.tabela[indice] = new Par<std::string, std::string>(chave1, valor1);

    tabela.inserir(chave1, novoValor);

    CHECK(tabela.tabela[indice]->getValor() == novoValor);
    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Sucessivamente e com Atualização") 
{
    std::size_t tamanhoInicial = 13;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "VECHA";
    std::string valor2 = "VALOR2";

    std::string chave3 = "VEACH";
    std::string valor3 = "VALOR3";

    tabela.inserir(chave1, valor1);
    tabela.inserir(chave2, valor2);
    tabela.inserir(chave3, valor3);
    
    std::string novoValor = "NOVO";

    tabela.inserir(chave1, novoValor);
    tabela.imprimir();

    auto indice = tabela.hash(chave1);
    
    auto pPar = tabela.tabela[indice];

    CHECK(contemChave(pPar, chave1));
    CHECK(contemChave(pPar, chave2));
    CHECK(contemChave(pPar, chave3));
    CHECK_FALSE(contemChave(pPar, "!!!!"));
    CHECK_FALSE(tabela.possuiDuplicatas());
}
