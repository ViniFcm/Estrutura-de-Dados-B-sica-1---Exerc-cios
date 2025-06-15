//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TabelaHash_h
#define TabelaHash_h

#include "Par.h"
#include <string>

static const std::size_t TAMANHO_PADRAO = 17;
static const float CARGA_LIMITE_INFERIOR = 0.125f;
static const float CARGA_LIMITE_SUPERIOR = 0.5f;
static const auto REMOVIDO = (Par<std::string, std::string>*)(-1);

class TabelaHash {
public:
    Par<std::string, std::string> **tabela;
    
    std::size_t tamanho;
    
    std::size_t quantidade;

    void setTamanho(const std::size_t&);
    
    void iniciar();
    
    std::size_t preHash(std::string&);
    
    std::size_t hash(std::string&);
    
    TabelaHash();
    
    TabelaHash(const std::size_t tamanho);
    
    ~TabelaHash();    
    
    std::size_t getTamanho();
    
    std::size_t getQuantidade();
    
    bool vazia();
    
    bool cheia();
    
    void imprimir();

    float fatorDeCarga();

    void aumentar();

    void diminuir();

    void redimensionar(const std::size_t&);
};


#endif /* TabelaHash_h */

