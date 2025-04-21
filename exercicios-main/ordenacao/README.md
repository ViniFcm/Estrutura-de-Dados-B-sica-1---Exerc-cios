# IMD0029 - Estruturas de Dados Básicas I, Prof. Eiji Adachi  
## Atividade de Fixação - Análise Empírica de Algoritmos de Ordenação

### 📁 Estrutura de Diretórios

```
ORDENACAO/
├── bin/                 # Executáveis gerados
├── data/                # Entradas e saídas dos testes
├── include/
│   └── ordenar.h        # Interface dos algoritmos de ordenação
├── src/
│   ├── main.cpp         # Código principal do experimento
│   └── seu_algoritmo_ordenacao.cpp
├── utils/
│   ├── entradas.py      # Gera os arquivos de entrada
│   └── grafico.py       # Gera gráficos de
└── README.md            # Este arquivo
```

### 🎯 Objetivos
- Exercitar a implementação de algoritmos de ordenação
- Realizar análise empírica de desempenho (tempo de execução) de diferentes algoritmos

---

### 📝 Descrição Geral

Você deverá implementar algoritmos de ordenação e medir o tempo de execução desses algoritmos com diferentes tamanhos de entrada e diferentes organizações dos dados de entrada (já ordenados em ordem crescente, em ordem decrescente, ou fora de ordem). O processo envolve as seguintes etapas:

---

### 🧪 Etapas da Atividade

Observação: todos os comandos mostrados a seguir assumem que você está executando-os a partir da raiz do diretório `ordenacao`.

#### 1. Gerar os arquivos de entrada

Execute o script `entradas.py`, localizado no diretório `utils`, para gerar os arquivos de entrada que serão usados nos testes.

```bash
python utils/entradas.py
```

Isso criará três arquivos dentro da pasta `data/`:
- `entrada_aleatoria.txt`: strings aleatórias
- `entrada_crescente.txt`: strings ordenadas em ordem crescente
- `entrada_decrescente.txt`: strings ordenadas em ordem decrescente

---

#### 2. Implementar os algoritmos de ordenação

Para cada algoritmo de ordenação (ex: Selection Sort, Insertion Sort, Bubble Sort, Merge Sort e Quick Sort), crie um novo arquivo `.cpp` dentro do diretório `src/`.

Exemplo:
```bash
src/bubble_sort.cpp
src/merge_sort.cpp
```

Utilize a estrutura de `main.cpp` e o cabeçalho `ordenar.h` como base para seu código.

---

#### 3. Compilar o código

Compile seu código usando `g++`, salvando o executável na pasta `bin/`.

Exemplo:
```bash
g++ src/main.cpp src/bubble_sort.cpp o bin/bubble -Wall -pedantic -std=c++17
```

---

#### 4. Executar o experimento

Execute o arquivo gerado, passando dois argumentos:
1. Caminho do arquivo de entrada (`data/entrada_*.txt`)
2. Quantidade de strings a serem lidas (ex: 10000)

Redirecione a saída do programa para um arquivo `.csv` dentro da pasta `data/` usando o operador de redirecionamento de saída `>`.

Exemplo:
```bash
./bin/bubble data/entrada_aleatorio.txt 10000 > data/saida_bubble_aleatorio.csv

./bin/bubble data/entrada_crescente.txt 10000 > data/saida_bubble_crescente.csv

./bin/bubble data/entrada_decrescente.txt 10000 > data/saida_bubble_decrescente.csv
```

---

#### 5. Gerar o gráfico

Execute o script `grafico.py`, localizado na pasta `utils`, para gerar os gráficos a partir do arquivo `.csv` passado como parâmetro.

```bash
python utils/grafico.py data/saida_bubble_aleatorio.csv
```

Esse script irá gerar gráficos que ilustram o comportamento dos algoritmos de ordenação de acordo com o arquivo csv passado como parâmetro.

---