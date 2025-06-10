//
//  Fila.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Fila__
#define __Fila__

#include <string>
#include <sstream>
template <typename T>
class Fila
{
private: 
    T* elementos;
    int capacidade;
    int quantidade;
    int inicio;
    int fim;
    
public:
    Fila(int cap)
    {
        this->capacidade = cap;
        this->quantidade = 0;
        this->inicio = 0;
        this->fim = 0;
        elementos = new T[this->capacidade];
    }
    
    ~Fila()
    {
        delete [] elementos;
    }
    
    int tamanho()
    {
        return this->quantidade;
    }

    T frente()
    {
        if(this->vazia() == true){
        throw std::underflow_error("Vazia");
        return this->elementos[inicio];
        }
        return this->elementos[inicio];
    }

    void enfileirar(T elemento)
    {
        if(this->cheia() == true){
            return throw std::overflow_error("Cheia");
        }
        this->elementos[fim] = elemento;
        this->quantidade++;
        this->fim = (fim + 1)%capacidade;
    }

    T desenfileirar()
    {
        if(this->vazia() == true){
            throw std::underflow_error("Vazia");
            return this->elementos[inicio];
        }
        this->quantidade--;
        auto saiu = this->elementos[inicio];
        this->inicio = (inicio + 1)%capacidade;
        return saiu;
    }

    bool cheia()
    {
        return this->quantidade == this->capacidade;
    }

    bool vazia()
    {
        return this->quantidade == 0;
    }

    std::string imprimir()
    {
        std::stringstream resultado;
        resultado << "{ ";
        int i = this->inicio;
        int count = 0;
        while (count < this->quantidade) {
            resultado << this->elementos[i] << " ";
            i = (i + 1) % this->capacidade;
            ++count;
        }
        resultado << "}";
        return resultado.str();
    }
};

#endif