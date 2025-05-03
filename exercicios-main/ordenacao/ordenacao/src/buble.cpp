#include "../include/ordenar.h"

void ordenar(string array[], int tamanho){
    bool fez_swap = true;
    int fim = tamanho -1;
    while(fez_swap == true){
        fez_swap = false;
        for(int i = 0; i< fim; i++){
            if(array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                fez_swap = true;
            }
        }
        fim = fim -1;
    }

}