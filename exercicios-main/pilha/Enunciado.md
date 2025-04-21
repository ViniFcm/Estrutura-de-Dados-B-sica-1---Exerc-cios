# UFRN - EDB1 - Prof. Eiji Adachi

## Lista de Exercícios: Pilha

### Exercícios

1. **Expressões aritméticas pós-fixas** (`expressao.cpp`)
   
   Na notação infixa de expressões aritméticas, os operadores são escritos entre os operandos. Por exemplo: 1 + 2, ou 2 - 3 * 2. Já na notação pós-fixa, ou notação polonesa inversa, os operadores são escritos depois dos operandos.  Por exemplo: 1 2 +, ou 2 3 2 * -. Eis alguns outros exemplos de expressões infixas e correspondentes expressões pós-fixas:

| Expressão em notação Infixa | Expressão equivalente em notação Pós-fixa |
| --- | --- |
| 1 + 2	| 1 2 + | 
| 2 / 2	| 2 2 / | 
| 1 + 2 * 3	| 1 2 3 * + | 
| 1 * 2 + 3 - 4	| 1 2 * 3 + 4 - | 

Nesta questão, implemente a seguinte função: 

```c++ 
int resolverExpressao(std::vector<std::string> partesDaExpressao)
```

Essa função recebe como parâmetro de entrada um ``vector`` de ``strings`` representando uma expressão aritmética em notação pós-fixa e que retorna o seu valor numérico correspondente. Por exemplo: a expressão ``1 2 3 * + `` será representada no código da seguinte maneira: ``std::vector<std::string> entrada = {"1", "2", "3", "*", "+"}``.

Sua solução deverá, obrigatoriamente, usar uma pilha; para isso, use a estrutura ``stack`` da biblioteca padrão de C++. No arquivo ``Expressao.cpp``, existem exemplos de código de como declarar e manipular uma ``stack`` de C++ e como converter uma ``string`` em um valor inteiro.

2. **Expressões bem formadas** (`bemFormada.cpp`)

Nesta questão, implemente o seguinte método:


``` c++
bool Analisador::eBemFormada(std::string entrada)
```

Este método recebe como entrada uma string que representa uma sequência de chaves ``{}``, parênteses ``()`` e colchetes ``[]`` aninhados e verifica se o aninhamento dessa sequência é bem formada ou não. 

Uma sequência é considerada bem formada se:
- Cada abertura de parêntese, colchete ou chave tem um fechamento correspondente.
- Os fechamentos estão na ordem correta.

Por exemplo:

- A sequência ``{[()]()}`` é bem formada.
- A sequência ``[()`` não é bem formada, porque o primeiro colchete não tem um fechamento correspondente.
- A sequência ``[(])`` não é bem formada, porque os fechamentos não estão na ordem correta.

Obs.: Sua solução deverá, obrigatoriamente, usar uma pilha. Para isso, use uma ``stack`` da biblioteca padrão de C++. No arquivo Analisador.cpp há um exemplo de como iterar sobre os caracteres da string de entrada e como usar uma pilha do tipo ``stack``.

Obs.: Considere que o aninhamento entre os parênteses, as chaves e os colchetes podem ocorrer em qualquer ordem na sequência de entrada.

3. **Palíndromo** (`palindromo.cpp`)
Uma palavra, frase ou sequência é um palíndromo se ela lê da mesma forma de frente para trás e de trás para frente, ignorando espaços e pontuações. Por exemplo:  
- "ana" é palíndromo.  
- "arara" é palíndromo.  
- "a man a plan a canal panama" é palíndromo (ignorando espaços).

Neste exercício, implemente uma função que, dada uma string de entrada, determine se ela é um palíndromo utilizando uma pilha (considere que não serão usados pontuações nem letras com acentos). Sua solução deve ignorar espaços em branco na verificação se é ou não palíndromo.

```c++
bool ehPalindromo(string str);
```

---