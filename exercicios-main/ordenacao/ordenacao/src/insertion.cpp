#include "../include/ordenar.h"

void ordenar(string array[], int tamanho){
    for( int i = 1; i < tamanho; i++){
        auto novo = array[i];
        int j = i-1;
        while(j >= 0 && novo < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = novo;
    }
}