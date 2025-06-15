//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

bool TabelaHash::inserir(std::string& chave, std::string& valor)
{
   throw chave == valor;
}

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Par<std::string, std::string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
}

std::size_t TabelaHash::preHash(std::string& chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(std::string& chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(const std::size_t& tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}


bool TabelaHash::possuiDuplicatas()
{
    return false;
}

void TabelaHash::imprimir()
{
    for(std::size_t i = 0; i < this->getTamanho(); ++i)
    {
        if(this->tabela[i] == nullptr)
        {
            std::cout << "[" << i << "] = null" << std::endl;
        }
        else
        {
            std::cout << "[" << i << "] = " ;
            auto aux = this->tabela[i];
            while(aux!=nullptr)
            {
                std::cout << "{ " << aux->getChave() << "," << aux->getValor() << " } -> ";
                
                aux = aux->getProximo();
            }
            std::cout << "null" << std::endl;
            
        }
    }
}
