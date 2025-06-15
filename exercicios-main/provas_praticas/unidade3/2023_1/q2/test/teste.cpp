#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"
#include <iostream>

TEST_CASE("TabelaHash - Remover elemento deve decrementar o tamanho e registrar posição como REMOVIDO") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = "CHAVE";
    std::string valor = "VALOR";
    
    auto indice = tabela.hash(chave);

    tabela.tabela[indice] = new Par<std::string, std::string>(chave, valor);
    tabela.quantidade = 1;

    auto tamanhoAntes = tabela.getQuantidade();

    auto removeu = tabela.remover(chave);

    auto tamanhoDepois = tabela.getQuantidade();

    CHECK(removeu);

    CHECK(tamanhoAntes == tamanhoDepois + 1);

    CHECK(tabela.tabela[indice] == REMOVIDO);

    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("TabelaHash - Tentar remover elemento que não existe deve retornar falso e manter o tamanho") 
{
    std::size_t tamanhoInicial = 23;
    std::string chave = "CHAVE QUE NÃO EXISTE";
    
    TabelaHash tabela(tamanhoInicial);

    auto tamanhoAntes = tabela.getQuantidade();
    
    auto removeu = tabela.remover(chave);

    auto tamanhoDepois = tabela.getQuantidade();

    CHECK_FALSE(removeu);

    CHECK(tamanhoAntes == tamanhoDepois);

    CHECK_FALSE(tabela.possuiDuplicatas());
}

TEST_CASE("TabelaHash - Remover elemento sucessivamente com casos de colisão") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "ECHAV";
    std::string valor2 = "VALOR2";

    std::string chave3 = "VECHA";
    std::string valor3 = "VALOR3";
    
    auto indice1 = tabela.hash(chave1);
    auto indice2 = (indice1+1) % tabela.getTamanho();
    auto indice3 = (indice2+1) % tabela.getTamanho();

    tabela.tabela[indice1] = new Par<std::string, std::string>(chave1, valor1);
    tabela.tabela[indice2] = new Par<std::string, std::string>(chave2, valor2);
    tabela.tabela[indice3] = new Par<std::string, std::string>(chave3, valor3);
    tabela.quantidade = 3;

    tabela.remover(chave1);
    tabela.remover(chave2);
    tabela.remover(chave3);

    CHECK(tabela.vazia());

    CHECK(tabela.tabela[indice1] == REMOVIDO);
    CHECK(tabela.tabela[indice2] == REMOVIDO);
    CHECK(tabela.tabela[indice3] == REMOVIDO);

    CHECK_FALSE(tabela.possuiDuplicatas());
}
