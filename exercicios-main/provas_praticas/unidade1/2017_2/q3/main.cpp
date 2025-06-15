#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include "Sort.h"

using namespace std;

bool isOrdered(int[], int);

bool readInput(const string, int[], int);

int main(int argc, const char * argv[]) {
    if(argc != 2){
        cout << "Programa espera argumentos:\narg1 - indicando o caminho do arquivo de entrada" << endl;
        return -1;
    }
    
    const string path = argv[1];
    const int size = 50000;
    
    int* v = new int[size];
    bool read = readInput(path, v, size);
    if(!read)
    {
        return -1;
    }
    
    cout << "Input read correctly. Executing sorting..." << endl;
    
    sort(v, size);
    
    if( !isOrdered(v, size) )
    {
        cout << "Incorrect sorting." << endl;
        return -1;
    }

    int v1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(v1, sizeof(v1)/sizeof(int));
	assert( isOrdered(v1, sizeof(v1)/sizeof(int)) );

	int v2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort(v2, sizeof(v2)/sizeof(int));
	assert( isOrdered(v2, sizeof(v2)/sizeof(int)) );

	int v3[] = {5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, -1, -1, -1, -1, 10, 10};
    sort(v3, sizeof(v3)/sizeof(int));
	assert( isOrdered(v3, sizeof(v3)/sizeof(int)) );

    cout << "Sorting correct." << endl;
    
    return 0;
}

/*
 Checks if a given array is in ascending order.
 */
bool isOrdered(int v[], int size)
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

/*
 Reads file.
 */
bool readInput(const string path, int v[], int size){
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
