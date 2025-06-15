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
   // Não precisa de redimensionamento dinâmico
   
   auto hash = this->hash(chave);

    int indiceRemovido = -1;
    for(size_t delta = 0; delta < this->getTamanho(); delta++)
    {
        auto indice = (hash+delta) % this->getTamanho();

        auto elemento = this->array[indice];

        if(elemento == nullptr)
        {
            auto indiceInsercao = indiceRemovido == -1 ? indice : indiceRemovido;
            this->array[indiceInsercao] = new Par<std::string, std::string>(chave, valor);
            ++this->quantidade;
            return true;
        }
        else if(elemento == REMOVIDO)
        {
            indiceRemovido = indice;
        }
        else if(elemento->getChave() == chave)
        {
            elemento->setValor(valor);
            return true;
        }
    }
    return false;
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
    this->array = new Par<std::string, std::string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->array[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        auto entry = this->array[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] array;
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

bool TabelaHash::possuiDuplicatas()
{
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->array[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->array[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves!
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        auto elemento = array[i];
        if( elemento == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( elemento != nullptr )
        {
            std::cout << i << ": " << elemento->getChave() << ":" << elemento->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
