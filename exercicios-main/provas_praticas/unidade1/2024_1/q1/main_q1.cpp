#include <iostream>
#include <cassert>

using namespace std;

// Pode assumir que essa função só receberá números maiores ou iguais do que zero
bool consecutivosIguais(int N)
{
    throw "ERRO: Solução ainda não foi implementada";
}

int main(void)
{
    cout << "\t---\tQuestão 01: Início\t---" << endl;

    assert(consecutivosIguais(0) == false);
    assert(consecutivosIguais(9) == false);

    assert(consecutivosIguais(10) == false);
    assert(consecutivosIguais(98) == false);

    assert(consecutivosIguais(919) == false);
    assert(consecutivosIguais(1919) == false);

    assert(consecutivosIguais(11) == true);
    assert(consecutivosIguais(99) == true);

    assert(consecutivosIguais(1003456789) == true);
    assert(consecutivosIguais(1123456789) == true);

    cout << "\t---\tQuestão 01: Passou em todos os testes\t---" << endl;

    return 0;
}
