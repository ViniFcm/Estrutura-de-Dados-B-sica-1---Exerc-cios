#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"
#include <iostream>

bool possuiRemovido(Par<std::string, std::string> **tabela, std::size_t tamanho)
{
    for(size_t i = 0; i < tamanho; i++)
    {
        if(tabela[i] == REMOVIDO)
        {
            return true;
        }
    }

    return false;
}

bool elementoPermanece(Par<std::string, std::string> **tabela, std::size_t tamanho, std::string chave)
{
    for(size_t i = 0; i < tamanho; i++)
    {
        if(tabela[i] != nullptr && tabela[i] != REMOVIDO && tabela[i]->getChave() == chave)
        {
            return true;
        }
    }

    return false;
}

TEST_CASE("TabelaHash - Teste de Redimensionar sem removidos") 
{
    std::size_t tamanhoInicial = 7;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "ECHAV";
    std::string valor2 = "VALOR2";

    std::string chave3 = "VECHA";
    std::string valor3 = "VALOR3";

    std::string chave4 = "VEHAC";
    std::string valor4 = "VALOR4";
    
    auto indice1 = tabela.hash(chave1);
    auto indice2 = (indice1+1) % tabela.getTamanho();
    auto indice3 = (indice2+1) % tabela.getTamanho();
    auto indice4 = (indice3+1) % tabela.getTamanho();

    tabela.tabela[indice1] = new Par<std::string, std::string>(chave1, valor1);
    tabela.tabela[indice2] = new Par<std::string, std::string>(chave2, valor2);
    tabela.tabela[indice3] = new Par<std::string, std::string>(chave3, valor3);
    tabela.tabela[indice4] = new Par<std::string, std::string>(chave4, valor4);
    tabela.quantidade = 4;

    std::size_t novoTamanho = 17;

    tabela.redimensionar(novoTamanho);

    CHECK(tabela.getTamanho() == novoTamanho);
    CHECK(tabela.getQuantidade() == 4);

    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave1));
    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave2));
    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave3));
    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave4));

    CHECK_FALSE(possuiRemovido(tabela.tabela, novoTamanho));
}

TEST_CASE("TabelaHash - Teste de Redimensionar com removidos") 
{
    std::size_t tamanhoInicial = 7;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    // std::string chave2 = "ECHAV";
    // std::string valor2 = "VALOR2";

    std::string chave3 = "VECHA";
    std::string valor3 = "VALOR3";

    // std::string chave4 = "VEHAC";
    // std::string valor4 = "VALOR4";
    
    auto indice1 = tabela.hash(chave1);
    auto indice2 = (indice1+1) % tabela.getTamanho();
    auto indice3 = (indice2+1) % tabela.getTamanho();
    auto indice4 = (indice3+1) % tabela.getTamanho();

    tabela.tabela[indice1] = new Par<std::string, std::string>(chave1, valor1);
    tabela.tabela[indice2] = REMOVIDO;
    tabela.tabela[indice3] = new Par<std::string, std::string>(chave3, valor3);
    tabela.tabela[indice4] = REMOVIDO;
    tabela.quantidade = 2;

    std::size_t novoTamanho = 17;

    tabela.redimensionar(novoTamanho);

    CHECK(tabela.getTamanho() == novoTamanho);
    CHECK(tabela.getQuantidade() == 2);

    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave1));
    CHECK(elementoPermanece(tabela.tabela, novoTamanho, chave3));

    CHECK_FALSE(possuiRemovido(tabela.tabela, novoTamanho));
}