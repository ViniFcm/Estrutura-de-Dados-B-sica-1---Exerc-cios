// main.cpp
#include <iostream>
#include <chrono>
#include "busca.h"  // Inclui o cabeçalho da função de busca

int main() {
    const int maior_tamanho = 1000001;
    int arr[maior_tamanho];
    
    // Preenche o array com números em ordem crescente
    for (int i = 0; i < maior_tamanho; i++) {
        arr[i] = i;
    }

    int tamanho = 1;
    int step = 50000;
    int qtd_medicoes = 100;

    while(tamanho <= maior_tamanho)
    {
        for (int i = 0; i < qtd_medicoes; i++) {
            // Sempre busca a chave -10, que não está no array
            int chave = -10;

            // Inicia a medição do tempo da busca
            auto inicio = std::chrono::high_resolution_clock::now();
            
            // Chama a função de busca
            busca(arr, tamanho, chave);
            
            // Termina a medição do tempo
            auto fim = std::chrono::high_resolution_clock::now();

            // Calcula o tempo de execução em nanosegundos
            auto duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
            
            // Imprime o tamanho do array e o tempo de execução
            std::cout << tamanho << "," << duracao << std::endl;
        }
        
        tamanho += step;
    }

    return 0;
}
