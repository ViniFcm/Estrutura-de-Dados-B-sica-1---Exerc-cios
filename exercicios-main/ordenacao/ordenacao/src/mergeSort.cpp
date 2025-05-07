#include "../include/ordenar.h"

void intercalar(string array[], int inicio1, int inicio2, int fim2){
    int i = inicio1, fim1 = inicio2 -1, j = inicio2, k = 0;
    int tamanho = 1 + (fim2 - inicio1);
    string* temp = new string[tamanho];
    while(i <= fim1 && j <= fim2){
        if(array[i] <= array[j]){
            temp[k] = array[i];
            i++;
        }
        else if(array[j] < array[i]){
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while (i <= fim1)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    while (j <= fim2)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for(int x= inicio1, y = 0; x <= fim2; ++x, ++y ){
        array[x] = temp[y];
    }
    delete[] temp;
    
}

void mergeSort(string array[], int esquerda, int direita){
    if(esquerda < direita){
        int meio = esquerda+(direita-esquerda)/2 ;
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio + 1, direita);
        intercalar(array, esquerda, meio+1, direita);
        
    }
}

void ordenar(string array[], int tamanho){
    mergeSort(array, 0, tamanho -1);

}