#include "../include/ordenar.h"

std::pair<int,int> particionar(string array [], int esquerda, int direita){
    int i = esquerda;
    int j = direita;
    int k = direita - 1;
    auto pivo = array[direita];
    while(k >= i){
        if(array[k] < pivo){
            i++;
        }
        else if(array[k] > pivo){
            swap(array[j], array[k]);
            j--;
            k--;
        }
        else{
            k--;
        }
    }
    return std::make_pair(i,j);
}

int mediana3(string array[], int a, int b, int c){
    if( (array[a] >= array[b] && array[a] < array[c]) || (array[a] <= array[b] && array[a] > array[c]))
        return a;
    if( (array[b] > array[a] && array[b] <= array[c]) || (array[b] < array[a] && array[b] >= array[c]))
        return b;
    if( (array[c] >= array[a] && array[c] < array[b]) || (array[c] <= array[a] && array[c] > array[b]))
        return c;
    return c;

}

void QuickSort(string array[], int esquerda, int direita){
    if(esquerda < direita){
        int b = esquerda + (direita - esquerda)/2;
        int i_pivo = mediana3(array, esquerda,  b, direita);
        swap(array[i_pivo], array[direita]);
        pair<int,int> indiceDoPivo = particionar(array, esquerda, direita) ;
        QuickSort(array,esquerda, indiceDoPivo.first -1);
        QuickSort(array,indiceDoPivo.second +1, direita);
    }
}
void ordenar(string array[], int tamanho){
    QuickSort(array, 0, tamanho -1);

}