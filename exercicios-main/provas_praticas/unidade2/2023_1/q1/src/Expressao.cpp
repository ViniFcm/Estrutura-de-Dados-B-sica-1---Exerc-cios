#include "../include/Expressao.h"
#include <iostream>
#include <vector>
#include <stack>

bool adicao(std::string s)
{
    return s == "+";
}

bool subtracao(std::string s)
{
    return s == "-";
}

bool multiplicacao(std::string s)
{
    return s == "*";
}

bool divisao(std::string s)
{
    return s == "/";
}

bool operando(std::string s)
{
    return !adicao(s) && !subtracao(s) && !multiplicacao(s) && !divisao(s);
}

int resolverExpressao(std::vector<std::string> partesDaExpressao)
{
    std::stack<int> pilha;

    for(std::string parte : partesDaExpressao)
    {
        if( operando(parte) )
        {
            pilha.push( stoi(parte) );
        }
        else // significa que é um operador, i.e., +, -, *, /
        {
            int op2 = pilha.top();
            pilha.pop();
            int op1 = pilha.top();
            pilha.pop();

            int resultado;

            if(adicao(parte))
            {
                resultado = op1+op2;
            }
            else if(subtracao(parte))
            {
                resultado = op1-op2;
            }
            else if(multiplicacao(parte))
            {
                resultado = op1*op2;
            }
            else if(divisao(parte))
            {
                resultado = op1/op2;
            }
            else
            {
                throw "Operador não reconhecido.";
            }
            pilha.push(resultado);
        }
    }

    return pilha.top();
}