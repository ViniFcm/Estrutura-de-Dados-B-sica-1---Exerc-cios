#include "Lista.h"
#include <iostream>
#include <stdexcept>

Lista::Lista()
{
    this->quantidade = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

/**
 * @brief Destrutor da lista. Remove todos os nós alocados dinamicamente.
 */
Lista::~Lista()
{
    auto aux = this->primeiro;

    while(aux != nullptr)
    {
        auto tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->quantidade = 0;
}

/**
 * @brief Insere um elemento no início da lista.
 * 
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirInicio(const std::string& elemento)
{
    if(this->primeiro == nullptr){
        No* novo = new No(elemento);
        this->primeiro = novo;
        this->ultimo = novo;
        this->quantidade++;
        return true;
    }
    No* novo = new No(elemento);
    novo->proximo = this->primeiro;
    this->primeiro = novo;
    this->quantidade++;
    return true;
}

/**
 * @brief Insere um elemento no fim da lista.
 * 
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirFim(const std::string& elemento)
{
    if(this->primeiro == nullptr){
        return inserirInicio(elemento);
    }
    No* novo = new No(elemento);
    this->ultimo->proximo = novo;
    this->ultimo = novo;
    this->quantidade++;

}

/**
 * @brief Insere um elemento na posição i da lista.
 * 
 * @param i Posição onde o elemento será inserido.
 * @param elemento Elemento a ser inserido.
 * @return true se a inserção for realizada com sucesso.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho+1.
 */
bool Lista::inserirNaPosicao(int i, const std::string& elemento) 
{
    No* novo = new No(elemento);
    auto aux = this->primeiro;
    int j=1;
    while(j<i){
        aux = aux->proximo;
        j++;
    }
    auto aux1 = aux->proximo;
    aux->proximo = novo;
    novo->proximo = aux1;
    this->quantidade++;
    return true;
}

/**
 * @brief Remove o elemento do início da lista.
 * 
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
 */
bool Lista::removerInicio()
{
    if(this->primeiro == nullptr){
        return false;
    }
    auto aux = this->primeiro;
    this->primeiro = this->primeiro->proximo;
    delete aux;
    this->quantidade--;
    return true;

}

/**
 * @brief Remove o elemento do fim da lista.
 * 
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
 */
bool Lista::removerFim()
{
    if(this->ultimo == nullptr){
        return false;
    }
    if(this->ultimo == this->primeiro){
        return removerInicio();
    }
    auto aux1 = this->ultimo;
    auto aux = this->primeiro;
    while(aux->proximo != this->ultimo){
        aux = aux->proximo;
    }
    aux->proximo = nullptr;
    this->ultimo = aux;
    this->quantidade--;
    delete aux1;
    return true;

}

/**
 * @brief Remove o elemento da posição i da lista.
 * 
 * @param i Posição do elemento a ser removido.
 * @return true se o elemento for removido com sucesso.
 * * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
 */
bool Lista::removerNaPosicao(int i) 
{
    throw std::runtime_error("Ainda não foi implementado.");
}

/**
 * @brief Retorna o primeiro elemento da lista.
 * 
 * @return Referência constante para a string armazenada no primeiro nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string& Lista::primeiroElemento() const
{
    if (quantidade > 0)
    {
        return primeiro->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");
    }
}

/**
 * @brief Retorna o último elemento da lista.
 * 
 * @return Referência constante para a string armazenada no último nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string& Lista::ultimoElemento() const
{
    if (quantidade > 0)
    {
        return ultimo->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");
    }
}

/**
 * @brief Retorna o elemento armazenado na posição i da lista.
 * 
 * @param i Índice do elemento a ser acessado.
 * @return Referência constante para a string armazenada na posição i.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
 */
const std::string& Lista::elementoNaPosicao(int i) const 
{
    throw std::runtime_error("Ainda não foi implementado.");
}

/**
 * @brief Retorna o número de elementos armazenados na lista.
 * 
 * @return Quantidade de elementos.
 */
unsigned long Lista::tamanho() const
{
    return quantidade;
}

/**
 * @brief Imprime os elementos da lista no formato: { elem1, elem2, ... }
 */
void Lista::imprimir() const
{
    No* atual = primeiro;

    std::cout << "{ ";

    while (atual != nullptr)
    {
        std::cout << atual->valor << ", ";
        atual = atual->proximo;
    }

    std::cout << "} " << std::endl;
}

Lista::No::No(std::string valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

Lista::No::~No()
{
}