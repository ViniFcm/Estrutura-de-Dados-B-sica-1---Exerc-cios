//
//  Par.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef Par_h
#define Par_h

template <typename C, typename V>
class Par {
    
private:
    C chave;
    V valor;
    Par* proximo;
    
public:
    Par()
    {
    }
    
    Par(C chave, V valor):
    chave(chave), valor(valor), proximo(nullptr){}
    
    ~Par()
    {
        
    }
    
    C getChave()
    {
        return this->chave;
    }
    void setChave( C chave )
    {
        this->chave = chave;
    }
    
    V getValor()
    {
        return this->valor;
    }
    
    void setValor( V valor )
    {
        this->valor = valor;
    }

    Par* getProximo()
    {
        return this->proximo;
    }

    void setProximo(Par* p)
    {
        this->proximo = p;
    }
};

#endif 
