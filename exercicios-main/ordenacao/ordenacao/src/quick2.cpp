#include "../include/ordenar.h"
std::pair<int,int> particionar(string array[], int esquerda, int direita){
    auto pivo = array[direita];
    int i = esquerda;
    int k = direita -1;
    int j = direita;
    while(k >= i){
        if(array[k] < pivo){
            swap(array[k], array[i]);
            i++;
            k--;
        }
        else if(array[k] > pivo){
            swap(array[k], array[j]);
            j--;
            k--;
        }
        else{
          k--;  
        }
        
    }
    return std::make_pair(i, j);
}

void quickSort(string array[], int esquerda, int direita){
    if(esquerda < direita){
        std::pair<int,int> i_pivo = particionar(array, esquerda,direita);
        quickSort(array, esquerda, i_pivo.first -1);
        quickSort(array, i_pivo.second +1, direita);
    }
}
void ordenar(string array[], int tamanho){
    quickSort(array, 0, tamanho -1);
}