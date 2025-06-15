//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(): first(nullptr)
{
}

LinkedList::~LinkedList()
{
    if(this->getFirst()!=nullptr)
    {
        delete this->first;
    }
}

void LinkedList::setFirst(Node<string>* n)
{
    this->first = n;
}

Node<string>* LinkedList::getFirst(void)
{
    return this->first;
}

bool LinkedList::insertBegin(string s)
{
	std::cerr << "ERRO: Método LinkedList::insertBegin(string s) ainda não foi implementado." << std::endl;
    std::abort();
}

void LinkedList::print(void)
{
	for(auto n = this->getFirst(); n != nullptr; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

void LinkedList::invert()
{
	std::cerr << "ERRO: Método LinkedList::invert() ainda não foi implementado." << std::endl;
    std::abort();
}
