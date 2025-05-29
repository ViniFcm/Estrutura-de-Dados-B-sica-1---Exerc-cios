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
	
	int j =1;
	auto aux = this->cabeca->proximo;
	while(j < i){
		aux = aux->proximo;
		j++;
	}

    return aux->valor;
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{	
	
	int j = 1;
	auto aux = this->cabeca->proximo;
	do{
		if(aux->valor == s){
			return j;
		}
		
		aux = aux->proximo;
		j++;
		
	}while(aux->valor != s and j <= this->quantidade);

    return -1;
	
}

bool ListaDuplamenteEncadeada::inserirInicio(std::string s)
{   
    auto novo = new No<std::string>(s);
	//posiciona o Nó
	novo->anterior=this->cabeca;
	novo->proximo=this->cabeca->proximo;
	//Atualizar vizinhos
	this->cabeca->proximo->anterior = novo;
	this->cabeca->proximo = novo;
	//Quantidade;
	this->quantidade++;
	return true;

	
}

bool ListaDuplamenteEncadeada::inserirFim(std::string s)
{    
    auto novo = new No<std::string>(s);
	//posiciona o Nó
	novo->anterior=this->cauda->anterior;
	novo->proximo=this->cauda;
	//Atualizar vizinhos
	this->cauda->anterior->proximo = novo;
	this->cauda->anterior = novo;
	//Quantidade;
	this->quantidade++;
	return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{   
	if(i <0 or i > this->quantidade+1){
		return false;
	}
	if(i == 1){
		return inserirInicio(s);
	}
	if(i == this->quantidade+1){
		return inserirFim(s);
	}
	auto novo = new No<std::string>(s);
	int j =1;
	auto aux = this->cabeca->proximo;
	while(j < i){
		aux = aux->proximo;
		j++;
	}
	novo->proximo = aux;
	novo->anterior= aux->anterior;

	aux->anterior->proximo = novo;
	aux->anterior = novo;

	this->quantidade++;


    return true;
}

std::string ListaDuplamenteEncadeada::removerInicio(void)
{   
    auto aux = this->cabeca->proximo;
	//Desconectar Nó
	aux->proximo->anterior = aux->anterior;
	aux->anterior->proximo = aux->proximo;
	auto resultado = aux->valor;
	delete aux;
	this->quantidade--;
	return resultado;
}

std::string ListaDuplamenteEncadeada::removerFim(void)
{    
    auto aux = this->cauda->anterior;
	//Desconectar Nó
	aux->proximo->anterior = aux->anterior;
	aux->anterior->proximo = aux->proximo;
	auto resultado = aux->valor;
	delete aux;
	this->quantidade--;
	return resultado;
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
