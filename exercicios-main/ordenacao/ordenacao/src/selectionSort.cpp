#include "../include/ordenar.h"

void ordenar(string array[], int tamanho){
    for(int i = 0; i < tamanho;i++){
        int min = i;
        for(int j = i+1; j<tamanho; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            auto aux = array[i];
            array[i] = array[min];
            array[min] =  aux;
        }
    }
}