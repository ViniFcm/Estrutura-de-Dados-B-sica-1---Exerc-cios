#include <iostream>
#include <cassert>

using namespace std;

int posicaoInsercao(int array[], int esquerda, int direita, int alvo) 
{
    int inicio = esquerda;
    int fim = direita;
    while(inicio <= fim){
        int meio = inicio + (fim - inicio)/2;
        if(alvo < array[inicio]){
            return posicaoInsercao(array, meio)
        }
    }
}

int main(void)
{
    cout << "\t---\tQuestão 03: Início\t---" << endl;

    int array1[] = {1, 3, 5, 7};
    int tam = sizeof(array1) / sizeof(int);

    assert( posicaoInsercao(array1, 0, tam-1, 0) == 0);
    assert( posicaoInsercao(array1, 0, tam-1, 2) == 1);
    assert( posicaoInsercao(array1, 0, tam-1, 4) == 2);
    assert( posicaoInsercao(array1, 0, tam-1, 6) == 3);
    assert( posicaoInsercao(array1, 0, tam-1, 8) == 4);

    cout << "\t---\tQuestão 03: Passou em todos os testes\t---" << endl;
    
    return 0;
}
