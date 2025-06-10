//
//  ListaDuplamenteEncadeada.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
// 

#ifndef __ListaDuplamenteEncadeada__
#define __ListaDuplamenteEncadeada__

#include "No.h"
#include <string>

typedef enum {
    OK ,
    CABECA_NULA,
    CAUDA_NULA,
    CABECA_ANTERIOR,
    CABECA_PROXIMO_NULO,
    CAUDA_PROXIMO,
    CAUDA_ANTERIOR_NULO,
    CABECA_CAUDA,
    ENCADEAMENTO_INCORRETO
} StatusDaLista ;

class ListaDuplamenteEncadeada {
private:
    No<std::string>* cabeca;
    No<std::string>* cauda;
    int quantidade;
    
public:
    ListaDuplamenteEncadeada(void);
    ~ListaDuplamenteEncadeada(void);

    int buscar(std::string);
    
    bool inserirInicio(std::string); // Equivalente a inserir após a cabeça
    bool inserirFim(std::string);    // Equivalente a inserir antes da cauda
    bool inserir(int, std::string);  // Inserir de modo que se torne o i-ésimo elemento

    std::string removerInicio(void); // Equivalente a remover após a cabeça
    std::string removerFim(void);    // Equivalente ao remover do fim
    std::string remover(int);        // Remover o i-ésimo elemento

    const std::string primeiroElemento() const;
    const std::string ultimoElemento() const;
    const std::string elementoNaPosicao(int) const;
    
    StatusDaLista checarConsistencia(void);
    
    void imprimir(void);
    
    bool vazia(void);
    int tamanho(void);
};

#endif 
