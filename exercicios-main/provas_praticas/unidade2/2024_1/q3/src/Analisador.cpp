//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/Analisador.h"
#include <string>
#include <stack>

using namespace std;

Analisador::Analisador()
{
}

bool Analisador::eBemFormada(std::string str)
{
    // como declarar a pilha que armazenará caracteres do tipo char
    stack<char> pilha;

    // como iterar os carecteres da string de entrada
    for(char ch : str)
    {
        // como empilhar um caractere
        pilha.push(ch);

        // como acessar o caractere do topo da pilha
        char aux = pilha.top();

        if( ch == '(')
        {
            // como checar se uma pilha é vazia
            if(pilha.empty())
            {
                
            }
            else 
            {
                // como remover um elemento da pilha
                pilha.pop();
            }
        }
    }

    throw "ERRO: não implementou";
}
