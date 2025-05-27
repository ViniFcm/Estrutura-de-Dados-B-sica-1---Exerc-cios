#include "../include/ordenar.h"
int mediana3(string array[], int a, int b, int c){
    if( (array[a] >= array[b] && array[a] < array[c]) || (array[a] <= array[b] && array[a] > array[c]))
        return a;
    if( (array[b] > array[a] && array[b] <= array[c]) || (array[b] < array[a] && array[b] >= array[c]))
        return b;
    if( (array[c] >= array[a] && array[c] < array[b]) || (array[c] <= array[a] && array[c] > array[b]))
        return c;
    return c;

}
int particionar (string array[], int esquerda, int direita){
    int i_median = mediana3(array, esquerda, esquerda +(direita - esquerda)/2, direita);
    swap(array[i_median], array[direita]);
    string pivo = array[direita];
    int i = esquerda, j = direita - 1;
    while( i <= j){
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

void QuickSort(string array[], int esquerda, int direita){
    if(esquerda < direita){
        int i_pivo = particionar(array, esquerda, direita); ;
        QuickSort(array, esquerda, i_pivo - 1);
        QuickSort(array, i_pivo + 1, direita);
    }
}

void ordenar(string array[], int tamanho){
    QuickSort(array, 0, tamanho-1);

}