#include "../include/ordenar.h"
int particionar(string array[], int esquerda, int direita){
    auto pivo = array[direita];
    int i = esquerda;
    int j = direita -1;
    while(i <= j){
        while(i <= j && array[i] <= pivo){
            i++;
        }
        while(j >= i && array[j] > pivo){
            j--;
        }
        if(j >= i){
            swap(array[i], array[j]);
        }
    }
    swap(array[i], array[direita]);
    return i;
}

void quickSort(string array[], int esquerda, int direita){
    if(esquerda < direita){
        int i_pivo = particionar(array, esquerda,direita);
        quickSort(array, esquerda, i_pivo -1);
        quickSort(array, i_pivo +1, direita);
    }
}
void ordenar(string array[], int tamanho){
    quickSort(array, 0, tamanho -1);
}