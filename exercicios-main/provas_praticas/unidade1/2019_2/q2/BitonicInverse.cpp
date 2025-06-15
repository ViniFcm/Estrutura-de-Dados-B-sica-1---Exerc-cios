#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int findBase(vector<int> v, unsigned long left, unsigned long right)
{
    return -1;
}

int testCounter = 0;

bool test(vector<int> v, int expectedIndex)
{
    std::cout << "\tINÍCIO: Teste " << ++testCounter << endl;
    int counter = 0;
    for( int i : v )
        std::cout << counter++ << ":" << i << ", ";
    std::cout << "}\n";
    int r = findBase(v, 0, v.size()-1);
    
    std::cout << "Entrada: (dados abaixo estão  impressos no formato 'índice:valor')\n\t{" << std::endl;
    
    
    
    
    std::cout << "\nSaída:" << std::endl;
    if( v[r] != v[expectedIndex] )
    {
        std::cout << "\tResultado esperado era a base estar no índice " << expectedIndex << ", mas retornou o índice " << r << endl;
        return false;
    }
    else
    {
        std::cout << "\tResultado correto. O 'índice:valor' da base é: '" << r << ":" << v[r] << "'." << endl;
    }
    
    std::cout << "\tFIM: Teste " << testCounter << endl << endl;
    return true;
}

int main(void)
{
    int s = 50;
    
    // entradas
    vector<int> v1(s), v2(s), v3(s), v4(s), v5(s);
    for(int i = 0; i < s; i++)
    {
        v1[i] = i < s / 2 ? s-i : i; // decrescente + crescente
        v2[i] = 3*i; // crescente
        v3[i] = 3*s-3*i; // decrescente
        v4[i] = i < s / 3 ? 4*s-4*i : 3*i;
        v5[i] = i < s * 4 / 5 ? 7*s-4*i : 3*i;
    }
    
    // testes
    
    // v1 tem uma sequência inicial decrescente até 1/2, depois outra sequência crescente
    if( test(v1, s/2) == false )
    {
        std::cout << "!!!! Teste 1 falhou !!!!" << endl;
    }
    // v2 tem uma sequência inicial decresente vazia, depois uma sequência crescente
    else if( test(v2, 0) == false )
    {
        std::cout << "!!!! Teste 2 falhou !!!!" << endl;
    }
    // v3 tem uma sequência inicial descrescente, depois uma sequência crescente vazia
    else if( test(v3, s-1) == false )
    {
        std::cout << "!!!! Teste 3 falhou !!!!" << endl;
    }
    // v4 tem uma sequência inicial decrescente até 1/3, depois outra sequência crescente
    else if( test(v4, s/3) == false )
    {
        std::cout << "!!!! Teste 4 falhou !!!!" << endl;
    }
    // v5 tem uma sequência inicial decrescente até 4/5, depois outra sequência crescente
    else if( test(v5, s*4/5) == false )
    {
        std::cout << "!!!! Teste 5 falhou !!!!" << endl;
    }
    else
    {
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        std::cout << "!!!! FIM: Todos testes passaram !!!!" << endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }
    return 0;
}
