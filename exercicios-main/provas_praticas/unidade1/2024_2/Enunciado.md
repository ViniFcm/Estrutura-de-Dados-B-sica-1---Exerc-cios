# IMD0029 - Estruturas de Dados 1 - 2024.1 - Unidade 1
# Prof. Eiji Adachi

## **LEIA ANTES DE COMEÇAR**

- Atividade individual sem consulta a pessoas ou materiais (impresso ou eletrônico).
- O valor de cada questão está indicado no enunciado.
- Mantenha celulares e outros eletrônicos desligados durante a prova.
- Desvios éticos resultarão em nota zero nesta unidade.
- Você recebeu diretórios para cada questão, cada um contendo uma assinatura de função e uma função `main` com um teste simples. Para executá-lo, compile o arquivo `main.cpp` e rode-o via linha de comando.
- Siga a assinatura de função fornecida; não a altere. Se necessário, crie funções auxiliares, mas mantenha a assinatura original.

### Critérios de Correção

Na correção desta atividade, serão considerados:

- **Obediência às regras** das assinaturas de função e do entregável (arquivo .zip e estrutura de diretórios), conforme especificado.
- **Ausência de erros ou warnings** na compilação do código-fonte. Compile usando `g++` com as opções `-Wall -pedantic`.
- **Execução correta dos programas**, sem falhas e produzindo os resultados esperados.
- **Atendimento aos critérios de complexidade**, se estabelecidos no enunciado.
- **Qualidade do código-fonte**: boa apresentação, organização, identação, nomes de variáveis adequados, modularização em funções, etc.

**Observação:** Cada questão inclui um teste executável simples, que não garante a total corretude da sua implementação. Para a correção, será utilizada uma bateria de testes mais completa e o código será analisado manualmente.

### Entregável

- O entregável deve manter a mesma estrutura de diretórios do código-fonte recebido, contendo os arquivos de solução em cada diretório de questão.
- O diretório raiz deve ter seu nome, no formato `PRIMEIRO_NOME_SOBRENOME`. Exemplo:
  ```
  JOAO_SILVA
  ├── q1
  ├── q2
  └── q3
  ```
- Compacte toda a estrutura em um arquivo `.zip` (não use `.rar`, `.tar.gz` ou outros), seguindo o mesmo padrão de nome: `PRIMEIRO_NOME_SOBRENOME.zip`.
- O `.zip` não deve conter arquivos executáveis; remova arquivos objeto e executáveis antes de compactar.
- Entregue o arquivo via SIGAA até o horário estabelecido. Entregas após o prazo não serão aceitas, exceto em casos excepcionais (ex.: SIGAA fora do ar). Certifique-se de enviar a versão correta.

<div style="page-break-after: always;"/>

## Questão 1 - Valor: 1.5
Crie uma função recursiva que conta quantas vezes um determinado dígito `D` aparece em um número natural `N`. Por exemplo, se `N` for `1322333` e `D` for `3`, a função retorna `4`.

A função deve seguir a assinatura abaixo e ser implementada no arquivo q1/main_q1.cpp.
```c++
int contaDigito(int N, int D)
```

Obs.: Não utilize laços de repetição; apenas recursão.

## Questão 2 - Valor: 1.5
Implemente o algoritmo de ordenação Quick Sort de modo que os elementos do array estejam ordenados em ordem **DECRESCENTE**. Sua implementação deverá seguir a assinatura abaixo e deve ser implementada no arquivo ``q2/main_q2.cpp``.

``` c++
void quickSort(int array[], int esquerda, int direita)
```

 Obs.: A função auxiliar ``estaDecrescente`` não pode ser alterada.

## Questão 3 - Valor: 2.0

Dado um array ordenado de inteiros em ordem crescente e um elemento alvo, implemente uma função recursiva que determina a posição em que o elemento deveria ser inserido para manter o array ordenado. A posição retornada deve ser o índice onde o elemento alvo seria inserido, considerando que os elementos maiores que ele seriam deslocados para a direita. Assuma que o elemento alvo nunca existirá no array e que o array não possui elementos repetidos.

Por exemplo:

- Para o array `{10, 30, 50, 70}` e o elemento alvo `1`, a função deve retornar `0`, indicando que o elemento alvo deve ser inserido na posição de índice `0`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `40`, a função deve retornar `2`, indicando que o elemento alvo deve ser inserido na posição de índice `2`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `100`, a função deve retornar `4`, indicando que o elemento alvo deve ser inserido na posição de índice `4`. Neste caso, mesmo que o valor `4` não seja um índice válido no array de entrada, ele indica que o elemento alvo deveria ser inserido no fim do array após o elemento `70`.

Sua função deverá obrigatoriamente ser recursiva, ter complexidade Θ(lg(n)), seguir a assinatura abaixo e ser implementada no arquivo `q3/main_q3.cpp`:

```c++
int posicaoInsercao(int array[], int esquerda, int direita, int alvo)
```

Obs.: Não utilize laços de repetição; apenas recursão.
