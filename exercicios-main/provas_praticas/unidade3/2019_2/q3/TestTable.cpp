//
//  TestTable.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include "TestTable.h"
#include "HashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

extern HashEntry<std::string, std::string> *ENTRY_DELETED;

bool testar_Ajustar()
{
    cout << "\nINÍCIO: Testes Ajustar" << endl;

    HashTable table(7);

    vector<string> keys = {"a", "b", "c", "d", "e", "f", "g"};

    for(string key : keys)
    {
        auto index = table.hash(key);

        table.data[index] = new HashEntry<string, string>(key, "Value");
        ++table.quantity;
    }

    auto oldData = table.data;

    table.resize(17);

    auto newData = table.data;

    if( table.getSize() != 17 )
    {
        cout << "\t*ERRO - Teste Ajustar: Atributo 'size' não foi atualizado corretamente." << endl;
        return false;
    }
    if( oldData == newData )
    {
        cout << "\t*ERRO - Teste Ajustar: Atributo 'data' não foi redimensionado corretamente." << endl;
        return false;
    }

    for(string key : keys)
    {
        bool found = false;

        for(auto i = 0; i < table.getSize(); ++i)
        {
            if( table.data[i] != nullptr && table.data[i]->getKey() == key )
            {
                found = true;
                break;
            }
        }

        if( not found )
        {
            cout << "\t*ERRO - Teste Ajustar: Chave '" << key << "' estava na  tabela antes do 'resize' e não foi encontrada após." << endl;
            return false;
        }
    }

    for(auto i = 0; i < table.getSize(); ++i)
    {
        if(table.data[i] == nullptr || table.data[i] == ENTRY_DELETED)
        {
            continue;
        }

        auto element = table.data[i]->getKey();

        if( std::find( keys.begin(), keys.end(), element ) == keys.end() )
        {
            cout << "\t*ERRO - Teste Ajustar: HashEntry com chave '" << element << "' está na tabela após o 'resize' mas não estava antes." << endl;
            return false;
        }
    }

    cout << "\nFIM: Testes Ajustar" << endl;

    return true;
}

bool testar_Construtor()
{
    auto size = 17;

    HashTable* table = new HashTable(size);

    if( table->getSize() != size )
    {
        cout << "\t*ERRO - Teste Construtor: Atributo 'size' não foi inicializado corretamente." << endl;
        return false;
    }

    if( table->getQuantity() != 0 )
    {
        cout << "\t*ERRO - Teste Construtor: Atributo 'quantity' não foi inicializado corretamente." << endl;
        return false;
    }

    if( table->data == nullptr )
    {
        cout << "\t*ERRO - Teste Construtor: Atributo 'data' não foi inicializado corretamente." << endl;
        return false;   
    }

    for(auto i = 0; i < table->getSize(); ++i)
    {
        if( table->data[i] != nullptr )
        {
            cout << "\t*ERRO - Teste Construtor: " << i << "-ésimo elemento do atributo 'data[]' não foi inicializado corretamente." << endl;
            return false;
        }
    }

    delete table;

    return true;
}
