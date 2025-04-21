# UFRN - EDB1 - Prof. Eiji Adachi

## Roteiro para Atividade Prática em Laboratório - Análise Empírica de Algoritmos

---

## 1. Introdução: O que é Análise Empírica de Algoritmos?

A **análise empírica de algoritmos** é uma abordagem prática que envolve a implementação e execução real de algoritmos para avaliar seu desempenho em situações concretas. Diferentemente da análise teórica, que utiliza modelos matemáticos para estimar a complexidade dos algoritmos, a análise empírica permite observar como eles se comportam em ambientes reais, considerando fatores como arquitetura de hardware, otimizações do compilador, sistema operacional e detalhes específicos da implementação.

Esta metodologia está alinhada com os princípios do **método científico**, que consistem em formular hipóteses, realizar experimentos controlados, coletar dados mensuráveis e analisar os resultados para confirmar ou refutar as suposições iniciais. No contexto da ciência da computação, isso significa implementar algoritmos, executar testes com entradas variadas, medir o desempenho e interpretar os resultados.

Nesta atividade prática, você irá aplicar a análise empírica medindo o **tempo de execução** de duas funções de busca em C++: a **busca sequencial** e a **busca binária**. O objetivo é comparar o desempenho desses algoritmos para diferentes tamanhos de arrays e compreender como eles escalam com o aumento da quantidade de dados. Isso permitirá que você visualize na prática conceitos importantes sobre eficiência algorítmica e complexidade temporal.

Para medir o tempo de execução das funções de busca, utilizaremos a biblioteca `<chrono>` do C++. Essa biblioteca fornece ferramentas precisas para cronometrar intervalos de tempo, permitindo capturar com exatidão a duração das execuções dos algoritmos. Com os dados coletados, será possível criar gráficos que ilustram o comportamento dos algoritmos, verificar se correspondem às expectativas teóricas e observar como fatores práticos podem afetar o desempenho.

## 2. Implementação do Código em C++

A seguir, apresentamos o código básico para o arquivo `main.cpp` e o arquivo `busca.h`. Você deve **digitar o código manualmente** em seu editor de texto preferido, evitando copiar e colar. Essa prática ajuda na assimilação do conteúdo e na familiarização com a sintaxe do C++.

**Arquivo `main.cpp`:**

```cpp
// main.cpp
#include <iostream>
#include <chrono>
#include "busca.h"  // Inclui o cabeçalho da função de busca

int main() {
    const int maior_tamanho = 1000001;  // Define o tamanho máximo do array
    int arr[maior_tamanho];

    // Preenche o array com números em ordem crescente
    for (int i = 0; i < maior_tamanho; i++) {
        arr[i] = i;
    }

    int tamanho = 1;          // Tamanho inicial do array
    int passo = 50000;        // Incremento do tamanho do array a cada iteração
    int qtd_medicoes = 100;   // Quantidade de medições para cada tamanho

    // Loop para variar o tamanho do array até o tamanho máximo
    while (tamanho <= maior_tamanho) {
        // Realiza múltiplas medições para o tamanho atual
        for (int i = 0; i < qtd_medicoes; i++) {
            int chave = -10;  // Chave a ser buscada (não está presente no array)

            // Inicia a medição do tempo
            auto inicio = std::chrono::high_resolution_clock::now();

            // Chama a função de busca
            busca(arr, tamanho, chave);

            // Termina a medição do tempo
            auto fim = std::chrono::high_resolution_clock::now();

            // Calcula a duração em nanosegundos
            auto duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();

            // Imprime o tamanho do array e o tempo de execução
            std::cout << tamanho << "," << duracao << std::endl;
        }
        tamanho += passo;  // Incrementa o tamanho do array
    }

    return 0;
}
```

**Explicação do `main.cpp`:**

- **Bibliotecas Incluídas:**
  - `<iostream>`: Para operações de entrada e saída.
  - `<chrono>`: Para medir o tempo de execução.
  - `"busca.h"`: Declaração da função de busca que será implementada.

- **Variáveis Principais:**
  - `maior_tamanho`: Define o tamanho máximo do array a ser testado.
  - `arr`: O array de inteiros que será utilizado nas buscas.
  - `tamanho`: Tamanho atual do array em cada iteração.
  - `passo`: Valor pelo qual o tamanho do array será incrementado a cada iteração.
  - `qtd_medicoes`: Número de vezes que a busca será realizada para cada tamanho, permitindo uma média mais confiável.

- **Preenchimento do Array:**
  - O array é preenchido com números em ordem crescente, o que é essencial para o funcionamento correto da busca binária.

- **Loop Principal:**
  - O loop `while` ajusta o tamanho do array para cada conjunto de medições.
  - O loop interno `for` realiza múltiplas medições para o tamanho atual do array.

- **Medição do Tempo:**
  - Utiliza `std::chrono::high_resolution_clock` para obter alta precisão na medição.
  - A duração é calculada em nanosegundos e impressa juntamente com o tamanho do array.

**Arquivo `busca.h`:**

```cpp
// busca.h
#ifndef BUSCA_H
#define BUSCA_H

// Declaração da função de busca
int busca(const int* arr, int tamanho, int chave);

#endif // BUSCA_H
```

**Explicação do `busca.h`:**

- **Guardas de Inclusão:**
  - Evitam múltiplas inclusões do mesmo arquivo durante a compilação.

- **Declaração da Função:**
  - `int busca(const int* arr, int tamanho, int chave);`
    - `arr`: Ponteiro para o array onde será realizada a busca.
    - `tamanho`: Tamanho do array ou segmento do array a ser considerado.
    - `chave`: O valor a ser buscado no array.

**Implementação das Funções de Busca:**

Você deve criar dois arquivos separados, um para cada algoritmo de busca. Não fornecemos a implementação das funções, pois o objetivo é que você as desenvolva.

1. **Arquivo `busca_sequencial.cpp`:**

```cpp
// busca_sequencial.cpp
#include "busca.h"

int busca(const int* arr, int tamanho, int chave) {
    // Implemente aqui a busca sequencial
}
```

2. **Arquivo `busca_binaria.cpp`:**

```cpp
// busca_binaria.cpp
#include "busca.h"

int busca(const int* arr, int tamanho, int chave) {
    // Implemente aqui a busca binária
}
```

**Dicas para Implementação:**

- **Busca Sequencial:**
  - Percorra o array do início ao fim, comparando cada elemento com a chave.
  - Retorne o índice se a chave for encontrada ou `-1` se não for.

- **Busca Binária:**
  - Assuma que o array está ordenado (portanto, não precisa checar isso ou tentar ordená-lo).
  - Crie uma função de busca auxiliar com parâmetros de início e fim para poder dividir o array ao meio repetidamente. A função busca que recebe o tamanho como parâmetro deve chamar essa função de busca auxiliar.
  - Retorne o índice se a chave for encontrada ou `-1` se não for.

## 3. Compilação dos Programas

Após implementar as funções de busca, você deve compilar o `main.cpp` junto com cada implementação, gerando dois executáveis separados.

- **Compilando a Busca Sequencial:**

```bash
g++ main.cpp busca_sequencial.cpp -o busca_sequencial -Wall -pedantic -std=c++17
```

- **Compilando a Busca Binária:**

```bash
g++ main.cpp busca_binaria.cpp -o busca_binaria -Wall -pedantic -std=c++17
```

**Explicação dos Parâmetros de Compilação:**

- `g++`: Chama o compilador de C++.
- `-o busca_sequencial`: Define o nome do executável de saída.
- `-Wall`: Ativa todos os avisos do compilador, ajudando a identificar possíveis erros.
- `-pedantic`: Enfatiza a conformidade estrita ao padrão C++.
- `-std=c++17`: Especifica a versão do padrão C++ a ser utilizada.

**Notas Importantes:**

- Verifique se não há erros ou avisos após a compilação.
- Caso existam, revise seu código para corrigi-los antes de prosseguir.

## 4. Execução e Geração dos Dados

Com os executáveis prontos, você irá executá-los e redirecionar a saída para arquivos `.csv`, que armazenarão os dados coletados.

- **Executando a Busca Sequencial:**

```bash
./busca_sequencial > sequencial.csv
```

- **Executando a Busca Binária:**

```bash
./busca_binaria > binaria.csv
```

**Explicação do Redirecionamento de Saída:**

- O operador `>` captura tudo o que seria exibido no terminal e salva no arquivo especificado.
- Os arquivos `.csv` gerados conterão pares de valores: tamanho do array e tempo de execução. Eles servirão de entrada para a etapa posterior, na qual geraremos gráficos para comparar os tempos de execução de duas soluções.

**Verificando os Arquivos Gerados:**

- Abra os arquivos `sequencial.csv` e `binaria.csv` com um editor de texto ou uma ferramenta de planilha para verificar se os dados foram registrados corretamente.

## 5. Geração de Gráficos com Python

Para visualizar os resultados e comparar o desempenho dos algoritmos, utilizaremos um script Python chamado `comparar_graficos.py`.

**Preparação do Ambiente Python:**

1. **Criando um Ambiente Virtual:**

```bash
python -m venv meuambiente
```

2. **Ativando o Ambiente Virtual:**

- **No Windows:**

  ```bash
  meuambiente\Scripts\activate
  ```

- **No Linux ou macOS:**

  ```bash
  source meuambiente/bin/activate
  ```

3. **Instalando as Bibliotecas Necessárias:**

   Com o ambiente virtual ativado, instale as bibliotecas necessárias usando o `pip`:

   ```bash
   pip install pandas matplotlib numpy
   ```

4. **Executando o Script Python:**

   Ainda com o ambiente virtual ativado, execute o script Python passando os arquivos `.csv` gerados anteriormente:

   ```bash
   python comparar_graficos.py sequencial.csv binaria.csv
   ```

5. **Desativando o Ambiente Virtual:**

   Após concluir a execução do script e as análises necessárias, você pode desativar o ambiente virtual com o seguinte comando:

   - **No Windows:**

     ```bash
     deactivate
     ```

   - **No Linux ou macOS:**

     ```bash
     deactivate
     ```

   Ao desativar o ambiente virtual, você retorna ao ambiente padrão do sistema. Lembre-se de que as bibliotecas instaladas no ambiente virtual não estarão disponíveis até que você o ative novamente.

**O que o Script Faz:**

- Lê os dados dos arquivos `.csv` fornecidos.
- Plota as medições individuais como pontos (círculos) no gráfico.
- Calcula e plota uma linha de tendência para cada conjunto de dados, mostrando a relação entre o tamanho do array e o tempo de execução.
- Salva o gráfico gerado como um arquivo `.png` cujo nome é baseado nos arquivos de entrada.

**Observações:**

- Certifique-se de que os arquivos `.csv` e o script `comparar_graficos.py` estão no mesmo diretório.
- Se ocorrer algum erro, verifique se as bibliotecas foram instaladas corretamente e se os arquivos contêm os dados esperados.
- Após desativar o ambiente virtual, caso precise executar o script novamente ou instalar mais pacotes, será necessário reativá-lo.

**Exemplo de Saída do Script:**

- O script irá gerar um arquivo como `Comparacao_sequencial_binaria.png`.
- O gráfico mostrará claramente a diferença de desempenho entre os dois algoritmos, permitindo uma análise visual.

## 6. Outras Análises

Após concluir a atividade principal, você é encorajado a explorar outras possibilidades para aprofundar seu entendimento:

- **Comparar Versões Recursiva e Iterativa:**
  - Implemente a busca binária em sua forma recursiva e compare com a versão iterativa.
  - Analise se há diferença significativa no desempenho.

- **Variar Cenários de Busca:**
  - Modifique a chave de busca para um valor que esteja presente no array, como o primeiro, o último ou um valor intermediário.
  - Observe como isso afeta o tempo de execução, especialmente na busca sequencial.

- **Alterar Parâmetros de Teste:**
  - Ajuste o valor de `passo` para aumentar ou diminuir o intervalo de tamanhos testados.
  - Altere `qtd_medicoes` para realizar mais ou menos medições por tamanho.

- **Analisar o Impacto de Otimizações:**
  - Compile os programas com diferentes níveis de otimização do compilador (por exemplo: `g++ main.cpp busca_binaria.cpp -o binaria_o1 -O1 -Wall -pedantic -std=c++17` e `g++ main.cpp busca_binaria.cpp -o binaria_o3 -O3 -Wall -pedantic -std=c++17`) e compare os resultados dos dois executáveis gerados com níveis de otimização distintos.

Os níveis de otimização do compilador determinam quão intensivamente o compilador tenta melhorar o desempenho do código gerado durante a compilação. Ao utilizar opções como `-O1`, `-O2` ou `-O3` com o compilador `g++`, você instrui o compilador a aplicar diferentes conjuntos de otimizações:

  - -O1: Aplica otimizações básicas que melhoram o desempenho sem aumentar significativamente o tempo de compilação. Inclui remoção de código morto e simplificação de expressões.
  - -O2: Ativa um conjunto mais abrangente de otimizações que equilibram desempenho e tempo de compilação. Inclui todas as otimizações do nível -O1, além de melhorias como desdobramento de loops e otimização de chamadas de funções.
  - -O3: Realiza otimizações ainda mais agressivas, incluindo todas as do nível -O2, além de expansões de funções inline e vetorização de loops. Pode aumentar o tamanho do código e, em casos raros, introduzir comportamentos inesperados devido a reordenações mais intensivas.

Experimentar com esses níveis permite observar como as otimizações afetam o desempenho dos algoritmos em execução. Ao comparar os resultados, você compreenderá o impacto das otimizações na eficiência do código e poderá avaliar se os ganhos de desempenho justificam possíveis trade-offs, como aumento no tempo de compilação ou no tamanho do executável.

## 7. Conclusão

Esta atividade prática permite que você aplique o método científico na análise de algoritmos, fortalecendo sua capacidade de realizar experimentos, coletar dados e interpretar resultados. Ao compreender como os algoritmos se comportam na prática, você estará mais preparado para tomar decisões informadas sobre quais técnicas utilizar em diferentes contextos de programação.

**Dicas Finais:**

- **Colaboração:**
  - Discuta suas descobertas com colegas e professores para enriquecer o aprendizado coletivo.

- **Curiosidade:**
  - Não hesite em explorar além do proposto, pois a experimentação é fundamental para a inovação na computação.
