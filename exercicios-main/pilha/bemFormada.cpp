#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <string>
#include <stack>

using namespace std;

bool eBemFormada(string str)
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



TEST_CASE("Sequências bem formadas - Casos simples") 
{
    CHECK( eBemFormada("()") == true);
    CHECK( eBemFormada("[]") == true);
    CHECK( eBemFormada("{}") == true);
}

TEST_CASE("Sequências mal formadas - Casos simples") 
{
    CHECK( eBemFormada("(") == false);
    CHECK( eBemFormada("[") == false);
    CHECK( eBemFormada("{") == false);

    CHECK( eBemFormada(")") == false);
    CHECK( eBemFormada("]") == false);
    CHECK( eBemFormada("}") == false);
}

TEST_CASE("Sequências bem formadas - Casos aninhados") 
{
    CHECK( eBemFormada("(())()") == true);
    CHECK( eBemFormada("([]{}[])") == true);
    CHECK( eBemFormada("{([])}(){}({[][]{}})") == true);
}

TEST_CASE("Sequências mal formadas - Casos que sobram um caractere no fim") 
{
    CHECK( eBemFormada("()(") == false);
    CHECK( eBemFormada("[][") == false);
    CHECK( eBemFormada("{}{") == false);

    CHECK( eBemFormada("())") == false);
    CHECK( eBemFormada("[]{}(]") == false);
    CHECK( eBemFormada("{}(){}[]}") == false);
}

TEST_CASE("Sequências mal formadas - Casos que sobram um caractere no meio") 
{
    CHECK( eBemFormada("()({}") == false);
    CHECK( eBemFormada("[][{}") == false);
    CHECK( eBemFormada("{}{{}{}") == false);
}

TEST_CASE("Sequências mal formadas - Casos com fechamento com outro caracrtere") 
{
    CHECK( eBemFormada("(]") == false);
    CHECK( eBemFormada("(}") == false);
    
    CHECK( eBemFormada("{)") == false);
    CHECK( eBemFormada("{]") == false);

    CHECK( eBemFormada("[)") == false);
    CHECK( eBemFormada("[}") == false);

    CHECK( eBemFormada("(){]") == false);
    CHECK( eBemFormada("[](]{}") == false);
    CHECK( eBemFormada("{}(){]{}") == false);
}