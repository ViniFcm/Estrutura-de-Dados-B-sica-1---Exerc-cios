# UFRN - EDB1 - Prof. Eiji Adachi

## Roteiro de Atividade Prática em C++ - Compilação e Execução via Terminal no VS Code

### **Objetivos da Atividade**
- **Primário**: Praticar como compilar e executar programas em C++ pelo terminal de comandos utilizando o VS Code.
- **Secundário**: Praticar **programação em pares** e incentivar colaboração durante a programação.

### Pré-requisitos
- Ter o VSCode instalado (seguir instruções do site). 
- Ter o seguinte plugin instalado no VSCode: (i) C/C++ Extension Pack da Microsoft.

### **Instruções Gerais**

Esta atividade deverá ser feita em dupla para que se exercite a **programação em par**, que é uma técnica de desenvolvimento de software em que duas pessoas trabalham juntas em uma mesma tarefa, usando um único computador. Nessa técnica, a dupla assume dois papéis complementares: o **piloto (driver)** e o **navegador (navigator)**.

O piloto é a pessoa responsável por **escrever o código**. O piloto opera exclusivamente o teclado.
O navegador assume o papel de **revisar, orientar e discutir a implementação do código**. O navegador opera exclusivamente o mouse. A dinâmica de se progrmaar em par promove a revisão do código durante a sua escrita, o que pode melhorar a qualidade do código, ao mesmo tempo em que promove a colaboração e a troca de conhecimento entre os participantes. 

Nesta tarefa, após concluir uma tarefa, os papéis devem ser trocados para que ambos participem ativamente da escrita do código. 

### **Compilação e Execução no Terminal**:
No VS Code, crie um novo arquivo `.cpp` para cada tarefa proposta mais adiante. Após escrever o código, utilize o terminal para compilar e executar o programa. Não copie e cole o código dos programas a seguir; digite todo o código. Isso faz parte da atividade.
   
Para compilar, utilize o seguinte comandos no terminal, substituindo `arquivo` pelo nome do arquivo correspondente ao exercício:

```bash
g++ -std=c++20 -Wall -pedantic arquivo.cpp -o arquivo
```

Esse comando compila o arquivo usando o `g++` com a especificação `C++20` e habilita os avisos (`-Wall`) e o modo estrito (`-pedantic`) para ajudar a identificar potenciais problemas no código ainda em tempo de compilação. É importante ler atentamente as mensagens exibidas pelo compilador no terminal. 

Em seguida, para executar o programa que foi criado, utilize o seguinte comando:

```bash
./arquivo
```

Esse comando executa o programa gerado. Perceba que é necessário digitar o ponto-barra - ``./`` - antes do nome do programa para executá-lo.

<div style="page-break-after: always;"></div>

### **Programas a Serem Desenvolvidos**

#### **Programa 1: Calcular a Média dos Elementos de um Array**

Implemente uma função que:
- Recebe um array de inteiros e seu tamanho.
- Calcula e retorna o valor médio dos elementos.

**Exemplo de código**:
```cpp
#include <iostream>
using namespace std;

// Função que calcula o valor médio dos elementos de um array
double calcularMedia(int arr[], int tamanho) {
    // Sua implementação deve vir aqui
    return -1.0;
}

int main() {
    // Teste 1
    int arr1[] = {10, 20, 30, 40};
    int tamanho1 = 4;
    double media1 = calcularMedia(arr1, tamanho1);
    cout << "Teste 1 - O valor esperado era 25 e retornou " << media1 << endl;

    // Teste 2
    int arr2[] = {5, 15, 25, 35};
    int tamanho2 = 4;
    double media2 = calcularMedia(arr2, tamanho2);
    cout << "Teste 2 - O valor esperado era 20 e retornou " << media2 << endl;

    return 0;
}
```
<div style="page-break-after: always;"></div>

#### **Programa 2: Encontrar o Maior e Menor Elemento em um Array**

Implemente uma função que:
- Recebe um array de inteiros e seu tamanho.
- Retorna o maior e o menor elemento do array.

**Exemplo de código**:
```cpp
#include <iostream>
#include <utility>  // Necessário para std::pair
using namespace std;

// Função que encontra o maior e o menor elemento em um array
pair<int, int> encontrarMaiorMenor(int arr[], int tamanho) {
    // Sua implementação deve vir aqui
    int maior = arr[0];
    int menor = arr[0];
    return make_pair(maior, menor);  // Assim que faz para retornar um par (maior, menor)
}

int main() {
    // Teste 1
    int arr1[] = {10, 20, 5, 15, 30};
    int tamanho1 = 5;
    pair<int, int> resultado1 = encontrarMaiorMenor(arr1, tamanho1);
    cout << "Teste 1 - Maior esperado: 30, menor esperado: 5, retornou: " 
         << resultado1.first << " e " << resultado1.second << endl;

    // Teste 2
    int arr2[] = {50, 40, 60, 70, 20};
    int tamanho2 = 5;
    pair<int, int> resultado2 = encontrarMaiorMenor(arr2, tamanho2);
    cout << "Teste 2 - Maior esperado: 70, menor esperado: 20, retornou: " 
         << resultado2.first << " e " << resultado2.second << endl;

    return 0;
}
```

<div style="page-break-after: always;"></div>

#### **Programa 3: Verificar se um Array está Ordenado**

Implemente uma função que:
- Recebe um array de inteiros e seu tamanho.
- Verifica se o array está ordenado em ordem crescente e retorna `true` ou `false`.

**Exemplo de código**:
```cpp
#include <iostream>
using namespace std;

// Função que verifica se um array está ordenado em ordem crescente
bool verificarOrdenado(int arr[], int tamanho) {
    // Sua implementação deve vir aqui
    return false;
}

int main() {
    // Teste 1
    int arr1[] = {1, 2, 3, 4};
    int tamanho1 = 4;
    bool ordenado1 = verificarOrdenado(arr1, tamanho1);
    cout << "Teste 1 - Esperado: true, retornou: " << (ordenado1 ? "true" : "false") << endl;

    // Teste 2
    int arr2[] = {1, 2, 4, 3};
    int tamanho2 = 4;
    bool ordenado2 = verificarOrdenado(arr2, tamanho2);
    cout << "Teste 2 - Esperado: false, retornou: " << (ordenado2 ? "true" : "false") << endl;

    return 0;
}
```

<div style="page-break-after: always;"></div>

#### **Programa 4: Contar Elementos Repetidos em um Array**

Implemente uma função que:
- Recebe um array de inteiros e seu tamanho.
- Retorna o número de elementos que se repetem no array.

**Exemplo de código**:
```cpp
#include <iostream>
using namespace std;

// Função que conta elementos repetidos em um array
int contarRepetidos(int arr[], int tamanho) {
    // Sua implementação deve vir aqui
    return -1;
}

int main() {
    // Teste 1
    int arr1[] = {1, 2, 1, 3, 1};
    int tamanho1 = 5;
    int repetidos1 = contarRepetidos(arr1, tamanho1);
    cout << "Teste 1 - O valor esperado era 1 e retornou " << repetidos1 << endl;

    // Teste 2
    int arr2[] = {4, 5, 6, 7, 8};
    int tamanho2 = 5;
    int repetidos2 = contarRepetidos(arr2, tamanho2);
    cout << "Teste 2 - O valor esperado era 0 e retornou " << repetidos2 << endl;

    // Teste 3
    int arr3[] = {4, 4, 4, 4, 4};
    int tamanho3 = 5;
    int repetidos3 = contarRepetidos(arr3, tamanho3);
    cout << "Teste 3 - O valor esperado era 1 e retornou " << repetidos3 << endl;

    return 0;
}
```