//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "TestTable.h"
#include <iostream>
#include <cassert>

int main(int argc, const char * argv[]) {
    try
    {
        assert( testar_Construtor() );

        std::cout << "\n\nQUESTÃO 3 - HashTable::resize - Ajustar\n";
        assert( testar_Ajustar() );

        std::cout << "\tTodos os testes rodaram sem falhas.\n";
        
        return 0;
    }
    catch(...)
    {
        std::cerr << "\n\tFALHA GRAVE: Ocorreu alguma falha grave nos testes. Leia atentamente as mensagens acima.\n";
        return -1;
    }
}

