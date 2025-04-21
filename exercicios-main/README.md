# UFRN - EDB1 - Prof. Eiji Adachi

## Lista de Exercícios

Este repositório possui um conjunto de vários exercícios práticos. Para cada exercício, há um arquivo correspondente (`*.cpp`) onde você deve implementar sua solução. Cada arquivo já possui um conjunto de testes executáveis escritos usando o framework [Doctest](https://github.com/doctest/doctest), que ajudam a verificar se sua implementação está correta.

### O que são testes executáveis ?

Testes executáveis são pequenos programas que averiguam se unidades específicas da sua aplicação — neste caso, as funções que você implementará — funcionam como esperado. Eles verificam se a função está retornando os resultados esperados para uma série de entradas previamente selecionadas. Os testes executáveis são ferramentas úteis para controlar a qualidade do seu código, permitindo verificar rapidamente e frequentemente se o que você implementou está funcionando como deveria.

Considere, a título de exemplo, uma função simples que calcula a soma de dois números inteiros. Suponha que a função seja definida da seguinte forma:

```cpp
int soma(int a, int b) {
    return a + b;
}
```

Para verificar que a função `soma` está implementada corretamente, abaixo está um exemplo de como um teste executável pode ser implementado para esta função usando o framework Doctest:

```cpp
TEST_CASE("Teste da função soma") {
    CHECK(soma(2, 3) == 5); 
    CHECK(soma(-1, 1) == 0);
    CHECK(soma(0, 0) == 0); 
    CHECK(soma(100, 200) == 300); 
}
```

Neste exemplo, alguns casos são verificados:
- **`CHECK(soma(2, 3) == 5);`**: Verifica se a função `soma` retorna 5 quando os argumentos são 2 e 3.
- **`CHECK(soma(-1, 1) == 0);`**: Verifica se a função `soma` retorna 0 quando os argumentos são -1 e 1.
- **`CHECK(soma(0, 0) == 0);`**: Verifica se a função `soma` retorna 0 quando os argumentos são ambos 0.
- **`CHECK(soma(100, 200) == 300);`**: Verifica se a função `soma` retorna 300 quando os argumentos são 100 e 200.

Ao longo da disciplina, sempre usaremos testes executáveis, mas será responsabilidade do docente projetar e implementar os testes executáveis; os discentes irão apenas usá-los como apoio da implementação dos algoritmos e estruturas de dados estudados. Por isso, é importante aprender a compilar e executar os testes executáveis e a usá-los como uma ferramenta de apoio à implementação.

### Como compilar e executar os testes?

Para compilar, utilize o seguinte comandos no terminal, substituindo `<arquivo>` pelo nome do arquivo correspondente ao exercício:

```bash
g++ -std=c++20 -Wall -pedantic <arquivo>.cpp -o <arquivo> 
```

Esse comando compila o arquivo usando o g++ com a especificação C++20 e habilita os avisos (`-Wall`) e o modo estrito (`-pedantic`) para ajudar a identificar potenciais problemas no código ainda em tempo de compilação. É importante ler atentamente às mensagens exibidas pelo compilador no terminal. 

Em seguida, para executar o programa que foi criado, utilize o seguinte comando:

```bash
./<arquivo>
```

Esse comando executa o programa gerado. Perceba que é necessário digitar o ponto-barra - ``./`` - antes do nome do programa para executá-lo.

Se todos os testes passarem, sua implementação (provavelmente) está correta. Caso contrário, revise seu código para atender aos testes que falharam, prestando atenção nas mensagens de erro exibidas pelos testes.

<div style="page-break-after: always;"></div>

### Exercícios

1. [Manipulação de arrays](./array/Enunciado.md)
2. [Recursão](./recursao/Enunciado.md)
3. [Busca binária](./busca-binaria/Enunciado.md)
4. [Pilha](./pilha/Enunciado.md)