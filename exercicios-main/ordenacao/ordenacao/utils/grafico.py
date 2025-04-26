import argparse
import csv
import os.path
import matplotlib.pyplot as plt

# Parser de argumentos com suporte para 1 ou mais arquivos
parser = argparse.ArgumentParser(description='Gerar gráfico de tempo de execução em função do tamanho da entrada.')
parser.add_argument('csv_files', nargs='+', help='Um ou mais arquivos CSV contendo os dados')
args = parser.parse_args()

# Processa cada CSV fornecido
for csv_file in args.csv_files:
    with open(csv_file) as arquivo_csv:
        leitor_csv = csv.reader(arquivo_csv, delimiter=',')
        campos = next(leitor_csv)
        tamanhos = []
        tempos = []
        for linha in leitor_csv:
            tamanhos.append(int(linha[0]))
            tempos.append(float(linha[1]))

    label = os.path.basename(csv_file).replace('.csv', '')
    plt.plot(tamanhos, tempos, label=label)

# Personalização do gráfico
plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo (ms)')
plt.title('Tempo de execução em função do tamanho da entrada')
plt.legend()

# Define nome do arquivo de saída
base_names = "_vs_".join([os.path.splitext(os.path.basename(f))[0] for f in args.csv_files])
nome_saida = f'data/{base_names}_grafico_comparativo.png'

# Salva o gráfico
plt.savefig(nome_saida)
print(f'Gráfico salvo como {nome_saida}')