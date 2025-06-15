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
    
    bool remover(std::string& chave);
    
    std::size_t getTamanho();
    
    std::size_t getQuantidade();
    
    bool vazia();
    
    bool cheia();

    bool possuiDuplicatas();
    
    void imprimir();
};


#endif /* TabelaHash_h */

