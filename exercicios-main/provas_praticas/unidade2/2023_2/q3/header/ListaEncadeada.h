#include <string>
#include "No.h"

class ListaEncadeada
{
private:
    int quantidade;       
    No<std::string>* inicio;
    
public:
    ListaEncadeada();
    
    ~ListaEncadeada();
    
    void inserirNoInicio(std::string);

    bool e_simetrica();

    void imprimir();
    
    bool vazia();
    
    int tamanho();

    No<std::string>* getInicio();

    void setInicio(No<std::string>*);
};
