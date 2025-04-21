#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <string>
#include <stack>

using namespace std;

int resolverExpressao( std::vector<std::string> partesDaExpressao )
{
    stack<int> pilha;

    for(string parte : partesDaExpressao)
    {
        if( parte == "(")
        {
            pilha.push(10); // empilha
            int valor = pilha.top(); // verifica o topo
            pilha.pop(); // desempilha
        }
        else if( pilha.empty() ) // assim que se verifica se a pilha está vazia
        {
            
        }
        
        // É assi que se converte de string para inteiro
        int valor = stoi(parte);
    }

    return -1;
}

TEST_CASE("Resolver Expressão - Adição Simples") 
{
    std::vector<std::string> entrada = {"1", "0", "+"};
    
    CHECK(resolverExpressao(entrada) == 1);

    entrada = {"0", "1", "+"};
    
    CHECK(resolverExpressao(entrada) == 1);

    entrada = {"1", "1", "+"};
    
    CHECK(resolverExpressao(entrada) == 2);
}

TEST_CASE("Resolver Expressão - Subtração Simples") 
{
    std::vector<std::string> entrada = {"1", "0", "-"};
    
    CHECK(resolverExpressao(entrada) == 1);

    entrada = {"0", "1", "-"};
    
    CHECK(resolverExpressao(entrada) == -1);

    entrada = {"1", "1", "-"};
    
    CHECK(resolverExpressao(entrada) == 0);
}

TEST_CASE("Resolver Expressão - Multiplicação Simples") 
{
    std::vector<std::string> entrada = {"1", "0", "*"};
    
    CHECK(resolverExpressao(entrada) == 0);

    entrada = {"0", "1", "*"};
    
    CHECK(resolverExpressao(entrada) == 0);

    entrada = {"1", "10", "*"};
    
    CHECK(resolverExpressao(entrada) == 10);

    entrada = {"10", "1", "*"};
    
    CHECK(resolverExpressao(entrada) == 10);

    entrada = {"11", "3", "*"};
    
    CHECK(resolverExpressao(entrada) == 33);
}

TEST_CASE("Resolver Expressão - Divisão Simples") 
{
    std::vector<std::string> entrada = {"0", "2", "/"};
    
    CHECK(resolverExpressao(entrada) == 0);

    entrada = {"10", "1", "/"};
    
    CHECK(resolverExpressao(entrada) == 10);

    entrada = {"10", "10", "/"};
    
    CHECK(resolverExpressao(entrada) == 1);

    entrada = {"12", "3", "/"};
    
    CHECK(resolverExpressao(entrada) == 4);
}

TEST_CASE("Resolver Expressão - Expressões compostas") 
{
    std::vector<std::string> entrada = {"1", "2", "*", "3", "*"};
    
    CHECK(resolverExpressao(entrada) == 6);
    
    entrada = {"1", "2", "*", "3", "+", "4", "-"};
    
    CHECK(resolverExpressao(entrada) == 1);

    entrada = {"1", "3", "-", "3", "5", "-", "*"};
    
    CHECK(resolverExpressao(entrada) == 4);

    entrada = {"1", "2", "3", "*", "-", "4", "-"}; 
    CHECK(resolverExpressao(entrada) == -9);
}
