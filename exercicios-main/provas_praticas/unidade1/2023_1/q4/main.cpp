#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;

void ordenar(int v[], int tamanho)
{
    // Implemente aqui o Quick Sort
}

// Funções auxiliares usadas para testar
bool estaOrdenado(int[], int);
bool lerEntrada(const string, int[], int);

int main(int argc, const char * argv[]) {
    const string path = "./input.txt";
    const int size = 1000000;
    
    int* v = new int[size];
    bool read = lerEntrada(path, v, size);
    if(!read)
    {
        return -1;
    }
    
    cout << "Entrada lida corretamente. Ordenando..." << endl;
    
    ordenar(v, size);
    
    if( !estaOrdenado(v, size) )
    {
        cout << "FALHA: Não ordenou corretamente." << endl;
        return -1;
    }

    int v1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ordenar(v1, sizeof(v1)/sizeof(int));
	assert( estaOrdenado(v1, sizeof(v1)/sizeof(int)) );

	int v2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ordenar(v2, sizeof(v2)/sizeof(int));
	assert( estaOrdenado(v2, sizeof(v2)/sizeof(int)) );

	int v3[] = {5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, -1, -1, -1, -1, 10, 10};
    ordenar(v3, sizeof(v3)/sizeof(int));
	assert( estaOrdenado(v3, sizeof(v3)/sizeof(int)) );

    cout << "Ordenação correta." << endl;
    
    return 0;
}

/*
 Verifica se um array está em ordem crescente.
 */
bool estaOrdenado(int v[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(v[i-1] > v[i])
        {
            return false;
        }
    }
    
    return true;
}

bool lerEntrada(const string path, int v[], int size){
    ifstream file(path);
    
    if(!file.is_open())
    {
        cout << "Não foi possível abrir o arquivo: " << path << endl;
        return false;
    }
    
    int max;
    file >> max;
    
    if( size > max )
    {
        cout << "O arquivo " << path << " contém apenas " << max << " elementos." << endl;
        return false;
    }
    
    for( int i = 0; i < size; i++){
        int x;
        file >> x;
        v[i] = x;
    }
    
    file.close();
    
    return true;
}
