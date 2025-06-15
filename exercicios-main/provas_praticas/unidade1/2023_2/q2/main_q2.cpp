#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

void mergeSort(int[], int, int);
bool estaDecrescente(int [], int);

int main(void)
{
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int tamanho = 1000000;

    mergeSort(arrayAleatorio, 0, tamanho-1); // arrayAleatorio é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayAleatorio, tamanho) );

    mergeSort(arrayCrescente, 0, tamanho-1); // arrayCrescente é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayCrescente, tamanho) );
    

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
}

void merge(int array, int inicio1, int inicio2, int fim2)
{
    
}

void mergeSort(int array[], int esquerda, int direita)
{
    if(esquerda < direita)
    {
        int meio = (esquerda + direita) / 2;
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio+1, direita);
        merge(array, esquerda, meio, direita);
    }
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