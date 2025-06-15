//
//  Node.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__Node__
#define __LinkedList__Node__

#include <iostream>

template <typename T>
class Node
{
private:
    T value;
    Node<T>* next;
    Node<T>* prev;
    
public:
    Node();
    
    Node( T );
    
    Node( T, Node*, Node* );
    
    T getValue();
    
    void setValue(T val);
    
    Node* getNext();
    
    void setNext(Node*);
	
	Node* getPrevious();
	
	void setPrevious(Node*);
};

template<typename T>
Node<T>::Node(void):
next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(T val):
value(val), next(nullptr), prev(nullptr) {}

template<typename T>
T Node<T>::getValue(void)
{
    return this->value;
}

template<typename T>
Node<T>* Node<T>::getNext(void)
{
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    this->next = n;
}

template<typename T>
Node<T>* Node<T>::getPrevious(void)
{
	return this->prev;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* p)
{
	this->prev = p;
}

#endif /* defined(__LinkedList__Node__) */
