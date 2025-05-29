//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->proximo = this->cauda;
    this->cabeca->anterior = nullptr;

    this->cauda->proximo = nullptr;
    this->cauda->anterior = this->cabeca;

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
	auto aux = this->cabeca->proximo;

	while( aux != this->cauda )
	{
		auto tmp = aux;
		aux = aux->proximo;
		delete tmp;
	}

	delete this->cabeca;
	delete this->cauda;

	this->cabeca = nullptr;
	this->cauda = nullptr;
	this->quantidade = 0;
}

const std::string ListaDuplamenteEncadeada::primeiroElemento() const {
	return this->cabeca->proximo->valor;
}

const std::string ListaDuplamenteEncadeada::ultimoElemento() const {
	return this->cauda->anterior->valor;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
    return this->tamanho() == 0;
}

const std::string ListaDuplamenteEncadeada::elementoNaPosicao(int i) const
{
   return "";
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	return -1;
}

bool ListaDuplamenteEncadeada::inserirInicio(std::string s)
{   
    return false;
}

bool ListaDuplamenteEncadeada::inserirFim(std::string s)
{    
    return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    
    return true;
}

std::string ListaDuplamenteEncadeada::removerInicio(void)
{   
    return "";
}

std::string ListaDuplamenteEncadeada::removerFim(void)
{    
    return "";
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
    return "";
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->proximo; n != this->cauda; n = n->proximo)
	{
		std::cout << n->valor << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->proximo == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->proximo->anterior != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->anterior != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->anterior == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->anterior->proximo != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->proximo != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->proximo != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->anterior )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->proximo; i != this->cauda; i=i->proximo)
		{
			if( i->proximo->anterior != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->anterior->proximo != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
