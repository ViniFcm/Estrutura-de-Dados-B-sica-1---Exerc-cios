//
//  Deque.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Deque__
#define __Deque__ 

#include <string>
#include <sstream>
#include <stdexcept>

template <typename T>
class Deque
{
private:
    T* elementos;
    int capacidade;
    int quantidade;
    int frente;
    int atras;

public:
    Deque(int cap)
    {
        this->capacidade = cap;
        this->elementos = new T[this->capacidade];
        this->quantidade = 0;
        this->frente = 0;
        this->atras = 0;
    }

    ~Deque()
    {
        delete[] this->elementos;
    }

    int tamanho() const
    {
        return this->quantidade;
    }

    bool cheia() const
    {
        return this->quantidade == this->capacidade;
    }

    bool vazia() const
    {
        return this->quantidade == 0;
    }

    void empurrar_frente(T elemento)
    {
        if(this->cheia()==true){
            throw std::overflow_error("CHEIA");
        }
        this->frente = (frente - 1 + this->capacidade) % this->capacidade;
        this->elementos[frente] = elemento;
        this->quantidade++;
    }

    void empurrar_atras(T elemento)
    {
        if(this->cheia()==true){
            throw std::overflow_error("CHEIA");
        }
        this->quantidade++;
        //this->atras = (atras+1)%this->capacidade;
        this->elementos[atras] = elemento;
        this->atras = (atras+1)%this->capacidade;
    }

    T remover_frente()
    {
        if(this->vazia() == true){
            throw std::underflow_error("VAZIA");
            return this->elementos[this->frente];
        }
        auto x = this->elementos[this->frente];
        this->quantidade--;
        this->frente = (this->frente + 1)%this->capacidade;
        return x;
    }

    T remover_atras()
    {
        if(this->vazia() == true){
            throw std::underflow_error("VAZIA");
        }
        auto x = this->elementos[atras-1];
        this->quantidade--;
        this->atras = (atras - 1 + this->capacidade )%this->capacidade;
        return x;
    }

    T daFrente() const
    {
        if(this->vazia() == true){
            throw std::underflow_error("VAZIA");
            
        }
        return this->elementos[this->frente];
    }

    T deTras() const
    {
        if(this->vazia() == true){
            throw std::underflow_error("VAZIA");
            
        }
        return this->elementos[this->atras-1];
    }

    std::string imprimir() const
    {
        std::stringstream resultado;
        resultado << "{ ";
        int i = this->frente;
        for (int cont = 0; cont < this->quantidade; ++cont)
        {
            resultado << this->elementos[i] << " ";
            i = (i + 1) % this->capacidade;
        }
        resultado << "}";
        return resultado.str();
    }
};

#endif