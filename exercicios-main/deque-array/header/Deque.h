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
    }

    void empurrar_atras(T elemento)
    {
    }

    T remover_frente()
    {
    }

    T remover_atras()
    {
    }

    T daFrente() const
    {
    }

    T deTras() const
    {
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