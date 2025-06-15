//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <string>
#include <cassert>
#include "Dictionary.h"

using namespace std;

Dictionary<string, int>* buildMultiSet(string array[], int arraySize){
    Dictionary<string, int>* d = new Dictionary<string, int>();
    // Implemente sua solução aqui
    // Veja a observação no enunciado
    return d;
}

int main(int argc, const char * argv[]) {

    string array[] = {"A", "A", "B", "A", "B", "C"};
    int arraySize = 6;

    Dictionary<string, int>* d = buildMultiSet(array, arraySize); 

    assert(d->get("A") == 3);
    assert(d->get("B") == 2);   
    assert(d->get("C") == 1);   
    try{
        d->get("D"); // deve lançar uma exceção, pois D não está no dicionário
        assert(false); // não deveria executar esta linha
    }
    catch(std::out_of_range e){
        assert(true);
    }

    cout << "Teste OK!" << endl;
}
