#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

bool estaDecrescente(int [], int);

void quickSort(int array[], int esquerda, int direita)
{
    throw "ERRO: Solução ainda não foi implementada";
}

/**
 * Não altere a função main. 
 * Sua solução deve ser implementada na função quickSort.
*/
int main(void)
{
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int t1 = sizeof(arrayPequeno) / sizeof(int);

    cout << t1 << endl;

    quickSort(arrayPequeno, 0, t1-1); // arrayPequeno é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayPequeno, t1) );

    int t2 = sizeof(arrayGrande) / sizeof(int);

    quickSort(arrayGrande, 0, t2-1); // arrayGrande é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayGrande, t2) );

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
}

/**
 * Esta é uma função auxiliar que eu criei para poder testar se sua ordenação está correta. Não altere-a.
*/
bool estaDecrescente(int array[], int tamanho)
{
    for(int i = 0; i < tamanho-1; i++)
    {
        if( array[i] < array[i+1] )
        {
            return false;
        }
    }

    return true;
}