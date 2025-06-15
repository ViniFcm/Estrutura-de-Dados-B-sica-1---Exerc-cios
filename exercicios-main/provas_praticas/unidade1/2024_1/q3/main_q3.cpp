#include <iostream>
#include <cassert>

using namespace std;

int acharPico(int array[], int esquerda, int direita)
{
    throw "ERRO: Solução ainda não foi implementada";
}

/**
 * Não altere a função main. 
 * Sua solução deve ser implementada na função quickSort.
*/
int main(void)
{
    cout << "\t---\tQuestão 03: Início\t---" << endl;

    // array com sequência crescente seguida de decresente
    int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 95, 85, 75, 65, 55, 45};
    int tamanho1 = sizeof(array1) / sizeof(int);
    // Espera-se que o resultado dessa chamada seja igual a 9, pois é o índice do 100, que é o pico
    assert( acharPico(array1, 0, tamanho1-1) == 9);

    // array apenas com sequência crescente e sem sequência decresente
    int array2[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
    int tamanho2 = sizeof(array2) / sizeof(int);
    // Espera-se que o resultado dessa chamada seja igual a tamanho-1, pois é o índice do 95, que é o pico e o último elemento do array (o índice do último elemento é justamente tamanho-1)
    assert( acharPico(array2, 0, tamanho2-1) == tamanho2-1);

    // array apenas com sequência decrescente e sem sequência cresente
    int array3[] = {95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10};
    int tamanho3 = sizeof(array3) / sizeof(int);
    // Espera-se que o resultado dessa chamada seja igual a 0, pois é o índice do 95, que é o pico e o primeiro elemento do array
    assert( acharPico(array3, 0, tamanho3-1) == 0);

    cout << "\t---\tQuestão 03: Passou em todos os testes\t---" << endl;
    
    return 0;
}
