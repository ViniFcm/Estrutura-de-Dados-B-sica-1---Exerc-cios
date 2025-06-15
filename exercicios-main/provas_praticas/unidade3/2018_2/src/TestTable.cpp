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
    cout << "\nINÍCIO: Testes Construtor" << endl;

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

    cout << "FIM: Testes Construtor" << endl;

    return true;
}

bool testar_Inserir_CasoNormal()
{
    unsigned long tamanho = 17;
    HashTable* tabela = new HashTable(tamanho);
    
    bool inseriu = true;
    
    for(unsigned long i = 0; i < tamanho/2 && inseriu; i++)
    {
        string chaveStr = "chave-" + to_string(i);
        string valor = "conteudo-" + to_string(i);
        
        auto tamanhoAntes = tabela->getSize();
        auto qtdElementoAntes = tabela->getQuantity();
        
        inseriu = tabela->put(chaveStr, valor);
        
        auto tamanhoDepois = tabela->getSize();
        auto qtdElementoDepois = tabela->getQuantity();
        
        if( tamanhoAntes != tamanhoDepois )
        {
            cout << "\t*ERRO - Teste Inserir_CasoNormal: Tamanho foi modificado incorretamente. Tamanho só pode ser modificado quando ocorre redimensionamento." << endl;
            inseriu = false;
            break;
        }
        if( qtdElementoAntes != qtdElementoDepois-1 )
        {
            cout << "\t*ERRO - Teste Inserir_CasoNormal: Quantidade de elementos não foi incrementada corretamente." << endl;
            inseriu = false;
            break;
        }
    }
    
    delete tabela;
    
    return inseriu;
}

bool testar_Inserir_Atualizar()
{
    HashTable* tabela = new HashTable(7);
    
    string chave = "chave";
    string valor1 = "ConteudoInicial";
    string valor2 = "ConteudoAtualizado";
    
    tabela->put( chave, valor1 );
    
    tabela->put( chave, valor2 );
    
    bool resultado = true;
    
    if( tabela->getQuantity() == 1 )
    {
        for(unsigned long i = 0; i < tabela->getSize(); i++)
        {
            HashEntry<string, string> *entry = tabela->data[i];
            
            // A única entrada != null é a que foi atualizada com valor2
            // Se tiver alguém com value() != valor2, então está errado
            if( entry != nullptr && entry->getValue() != valor2)
            {
                cout << "\t*ERRO - Teste Inserir_Atualizar: Ao inserir dois itens com mesma chave, o valor do segundo deve sobrescrever valor do primeiro. Neste teste, dois elementos com mesma chave foram inseridos na tabela. O esperado era que o conteúdo do item na tabela fosse igual a '" << valor2 << "', mas valor encontrado foi igual a '" << entry->getValue() << "'." << endl;
                resultado = false;
                break;
            }
        }
    }
    else
    {
        cout << "\t*ERRO - Teste Inserir_Atualizar: Ao inserir dois itens com mesma chave, o valor do segundo deve sobrescrever valor do primeiro. Neste teste, dois elementos com mesma chave foram inseridos na tabela; o esperado era uma tabela com 1 item, mas a tabela ficou com " << tabela->getQuantity() << " itens." << endl;
        
        resultado = false;
    }
    
    delete tabela;
    
    return resultado;
}

bool testar_Inserir_Colisao()
{
    HashTable* tabela = new HashTable(17);
    string c1 = "abba";
    string i1 = "conteudo1";
    
    tabela->put(c1, i1);
    
    string c2 = "bbaa";
    string i2 = "conteudo2";
    
    tabela->put(c2,i2);
    
    bool achou1 = false, achou2 = false;
    for(unsigned long x = 0; x < tabela->getSize(); x++)
    {
        HashEntry<string, string> *entry = tabela->data[x];
        
        if( entry != nullptr && entry->getKey() == c1 )
        {
            achou1 = true;
        }
        
        if( entry != nullptr && entry->getKey() == c2 )
        {
            achou2 = true;
        }
    }
    
    bool resultado = true;
    if( (achou1 && !achou2)||(!achou1 && achou2) )
    {
        cout << "\t*ERRO - Teste Inserir_Colisao: Duas chaves que colidem foram inseridas, mas apenas uma foi encontrada na tabela. Provavelmente uma sobrescreveu a outra. Rever tratamento de colisão." << endl;
        resultado = false;
    }
    
    delete tabela;
    
    return resultado;
}

bool testar_Inserir_Apos_Remocao()
{
    HashTable table(7);
    
    auto index = table.hash("abcd");
    
    table.data[index] = new HashEntry<string, string>("abcd", "value1");
    table.data[ (index+1)%7 ] = new HashEntry<string, string>("bcda", "value2");
    table.data[ (index+2)%7 ] = ENTRY_DELETED;
    table.data[ (index+3)%7 ] = new HashEntry<string, string>("cdba", "value4");
    
    table.put("cdba", "NovoValor");
    
    auto entry = table.data[index+3];
    if( entry == nullptr || entry == ENTRY_DELETED || entry->getKey() != "cdba" || entry->getValue() != "NovoValor" )
    {
        cout << "\t*ERRO - Teste Inserir_Apos_Remocao: Não atualizou o valor da entrada corretamente quando existe uma posição removida no caminho das colisões." << endl;
        return false;
    }
    
    table.put("dabc", "value5");
    
    entry = table.data[index+2];
    if( entry == nullptr || entry == ENTRY_DELETED || entry->getKey() != "dabc" )
    {
        cout << "\t*ERRO - Teste Inserir_Apos_Remocao: Não inseriu corretamente quando existe uma posição removida no caminho das colisões." << endl;
        return false;
    }    
    
    return true;
}

bool testar_Inserir_Tabela_Sem_Null()
{
    HashTable table(7);
    
    auto index = table.hash("abcdef");
    
    table.data[index] = new HashEntry<string, string>("abcdef", "value0");
    table.data[ (index+1) % 7] = new HashEntry<string, string>("bcdefa", "value1");
    table.data[ (index+2) % 7] = new HashEntry<string, string>("cdefba", "value2");
    table.data[ (index+3) % 7] = new HashEntry<string, string>("cdeafb", "value3");
    table.data[ (index+4) % 7] = new HashEntry<string, string>("cdebaf", "value4");
    table.data[ (index+5) % 7] = new HashEntry<string, string>("cdebfa", "value5");
    table.data[ (index+6) % 7] = ENTRY_DELETED;

    auto result = table.put( "fabcde", "NovoValor" );

    if( result == false )
    {
        cout << "\t*ERRO - Teste testar_Inserir_Tabela_Sem_Null: Não inseriu corretamente quando existe uma posição removida numa tabela sem posições null." << endl;
        return false;
    }

    auto entry = table.data[(index+6) % 7];

    if( entry == nullptr || entry == ENTRY_DELETED || entry->getKey() != "fabcde" )
    {
        cout << "\t*ERRO - Teste testar_Inserir_Tabela_Sem_Null: Não inseriu corretamente quando existe uma posição removida no caminho das colisões." << endl;
        return false;
    } 


    return true;
}

bool testar_Inserir()
{
    cout << "\nINÍCIO: Testes Inserir" << endl;
    
    bool resultado = true;
    
    cout << "\tTeste Inserir - Caso Normal" << endl;
    resultado = testar_Inserir_CasoNormal();
    
    if(resultado)
    {
        cout << "\tTeste Inserir - Colisão" << endl;
        resultado = testar_Inserir_Colisao();
    }
    if(resultado)
    {
        cout << "\tTeste Inserir - Caso Atualizar" << endl;
        resultado = testar_Inserir_Atualizar();
    }
    if(resultado)
    {
        cout << "\tTeste Inserir - Caso Após Remoção" << endl;
        resultado = testar_Inserir_Apos_Remocao();
    }
    if(resultado)
    {
        cout << "\tTeste Inserir - Caso Tabela Sem Posição Null" << endl;
        resultado = testar_Inserir_Tabela_Sem_Null();
    }
    
    cout << "FIM: Testes Inserir" << endl;
    
    return resultado;
}

bool testar_Remover_CasoNormal()
{
    HashTable tabela(17);
    
    auto entry1 = new HashEntry<string, string>("a", "Valor1");
    auto entry2 = new HashEntry<string, string>("b", "Valor2");
    auto entry3 = new HashEntry<string, string>("c", "Valor3");

    tabela.data[ tabela.hash( entry1->getKey() ) ] = entry1;
    tabela.data[ tabela.hash( entry2->getKey() ) ] = entry2;
    tabela.data[ tabela.hash( entry3->getKey() ) ] = entry3;

    tabela.quantity += 3;
    
    auto qtdAntes = tabela.getQuantity();
    
    tabela.remove( entry2->getKey() );
    
    bool resultado = true;
    
    auto qtdDepois = tabela.getQuantity();
    
    if( qtdAntes - 1 != qtdDepois )
    {
        cout << "\t*ERRO - Teste Remover_CasoNormal: Não decrementou corretamente a quantidade de itens durante a remoção." << endl;
        resultado = false;
    }
    if( tabela.data[ tabela.hash( entry2->getKey() ) ] != ENTRY_DELETED )
    {
        cout << "\t*ERRO - Teste Remover_CasoNormal: Não marcou a posição como deletada." << endl;
        resultado = false;
    }
    
    bool achou = false;
    for(unsigned long x = 0; x < tabela.getSize(); x++)
    {
        HashEntry<string, string>* c = tabela.data[x];
        
        if( c == nullptr ) continue;
        if( c == ENTRY_DELETED ) continue;
        if( c->getKey() == entry2->getKey() )
        {
            achou = true;
            break;
        }
    }
    
    if(achou)
    {
        cout << "\t*ERRO - Teste Remover_CasoNormal: Remoção não foi feita corretamente, pois o item passado como parâmetro ainda foi encontrado na tabela." << endl;
        resultado = false;
    }
    
    delete entry1;
    // delete entry2;
    delete entry3;
    
    return resultado;
}

bool testar_Remover_Sucessivas()
{
    auto tamanho = 17;
    
    HashTable* tabela = new HashTable(tamanho);
    
    bool removeu = false;
    
    unsigned long qtdInserido = tabela->getSize()/2;
    unsigned long qtdRemovido = qtdInserido - 1 - tabela->getSize()/4;
    
    string base1 = "chave-";
    string base2 = "cheva-";
    string base3 = "hceva-";
    
    // Inicialização da tabela
    for(unsigned long i = 0; i < qtdInserido; i++)
    {
        string chave;
        
        if( i%3==0 )
        {
            chave = base1 + to_string(i);
        }
        else if( i%3==1 )
        {
            chave = base2 + to_string(i-1);
        }
        else
        {
            chave = base3 + to_string(i-2);
        }
        
        tabela->put(chave, "Conteudo" + to_string(i));
    }
    
    // Série de remoções com sucesso
    for(unsigned long i = 0; i < qtdRemovido; i++)
    {
        string chave;
        
        if( i%3==0 )
        {
            chave = base1 + to_string(i);
        }
        else if( i%3==1 )
        {
            chave = base2 + to_string(i-1);
        }
        else
        {
            chave = base3 + to_string(i-2);
        }
        
        auto qtdAntes = tabela->getQuantity();
        
        removeu = tabela->remove(chave);
        
        if(!removeu)
        {
            cout << "\t*ERRO - Teste Remover_Sucessivas: Não removeu corretamente item com chave igual a : " << chave << "." << endl;
            removeu = false;
            break;
        }
        
        auto qtdDepois = tabela->getQuantity();
        
        if( qtdAntes - 1 != qtdDepois )
        {
            cout << "\t*ERRO - Teste Remover_Sucessivas: Não decrementou corretamente a quantidade de itens durante a remoção." << endl;
            removeu = false;
            break;
        }
    }
    
    delete tabela;
    
    return removeu;
}

bool testar_Remover_Colisao()
{
    HashTable* tabela = new HashTable(17);
    string c1 = "abba";
    string i1 = "conteudo1";
    
    string c2 = "bbaa";
    string i2 = "conteudo2";
    
    string c3 = "baba";
    string i3 = "conteudo3";
    
    tabela->put(c1, i1);
    tabela->put(c2, i2);
    tabela->put(c3, i3);
    
    tabela->remove(c2);
    
    bool achou1 = false, achou3 = false;
    for(unsigned long x = 0; x < tabela->getSize(); x++)
    {
        HashEntry<string, string>* c = tabela->data[x];
        
        if( c != nullptr && c != ENTRY_DELETED && c->getKey() == c1  )
        {
            achou1 = true;
        }
        
        if( c != nullptr && c != ENTRY_DELETED && c->getKey() == c3  )
        {
            achou3 = true;
        }
    }
    
    bool resultado = true;
    if( (achou1 && !achou3)||(!achou1 && achou3) )
    {
        cout << "\t*ERRO - Teste Remover_Colisao: Três chaves que colidem foram inseridas e uma foi removida, mas foi removida a chave errada. Rever tratamento de colisão." << endl;
        resultado = false;
    }
    
    delete tabela;
    
    return resultado;
}

bool testar_Remover()
{
    cout << "\nINÍCIO: Testes Remover" << endl;
    
    bool resultado = true;
    
    cout << "\tTeste Remover - Caso Normal" << endl;
    resultado = testar_Remover_CasoNormal();
    
    if(resultado)
    {
        cout << "\tTeste Remover - Sucessivas" << endl;
        resultado = testar_Remover_Sucessivas();
    }
    
    if(resultado)
    {
        cout << "\tTeste Remover - Colisão" << endl;
        resultado = testar_Remover_Colisao();
    }
    
    cout << "FIM: Testes Remover" << endl;
    
    return resultado;
}
