//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include <chrono>
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include "../include/ordenar.h"

using namespace std;

void ler_entrada(const string, vector<string>&, int);
void testar_ordenacao(const vector<string>&, int);

int main(int argc, const char * argv[]) 
{
    if(argc != 3)
    {
        cerr << "ERRO: É necessário informar o caminho do arquivo de entrada e o tamanho do array a ser testado." << endl;
        cerr << "Uso: " << argv[0] << " <caminho_arquivo> <tamanho>" << endl;
        exit(-1);
    }

    string caminho_arquivo = argv[1];
    int tamanho = atoi(argv[2]);

    vector<string> v(tamanho);

    ler_entrada(caminho_arquivo, v, tamanho);
    testar_ordenacao(v, tamanho);

    return 0;
}

void testar_ordenacao(const vector<string>& entrada, int tamanho_total)
{
    int quantidade_medicoes = 10;
    int incremento = tamanho_total / quantidade_medicoes;
    int tamanho_ordenacao = tamanho_total / quantidade_medicoes;

    cout << "Tamanho,Tempo(milisegundos)" << endl;
    while(tamanho_ordenacao <= tamanho_total)
    {
        // Criar uma cópia do array original (trecho a ser ordenado)
        vector<string> copia(entrada.begin(), entrada.begin() + tamanho_ordenacao);

        auto inicio = chrono::high_resolution_clock::now();
        ordenar(copia.data(), tamanho_ordenacao);  // usar o ponteiro bruto
        auto fim = chrono::high_resolution_clock::now();

        auto duracao = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();

        cout << tamanho_ordenacao << "," << duracao << endl;

        tamanho_ordenacao += incremento;
    }
}

void ler_entrada(const string arquivo, vector<string>& v, int TAMANHO)
{
    ifstream arquivo_stream(arquivo);
    
    if(!arquivo_stream.good())
    {
        cerr << "ERRO: Arquivo não encontrado: " << arquivo << endl;
        exit(-1);
    }

    int i = 0;
    while (!arquivo_stream.eof() && i < TAMANHO)
    {
        string x;
        arquivo_stream >> x;
        if (!x.empty())
        {
            v[i] = x;
            i++;
        }
    }

    arquivo_stream.close();
}