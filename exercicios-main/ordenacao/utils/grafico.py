import argparse
import csv
import os.path
import matplotlib.pyplot as plt

# Cria um parser de argumentos
parser = argparse.ArgumentParser()
parser.add_argument('csv_file', help='Nome do arquivo CSV')
args = parser.parse_args()

# Abre o arquivo CSV e lê os dados
with open(args.csv_file) as arquivo_csv:
    leitor_csv = csv.reader(arquivo_csv, delimiter=',')
    campos = next(leitor_csv)
    tamanhos = []
    tempos = []
    for linha in leitor_csv:
        tamanhos.append(int(linha[0]))
        tempos.append(float(linha[1]))

# Gera o gráfico de linha
plt.plot(tamanhos, tempos)
plt.xlabel(campos[0])
plt.ylabel(campos[1])

# Define o título do gráfico
nome_arquivo = os.path.basename(args.csv_file)
titulo_grafico = f'Tempo de execução em função do tamanho da entrada ({nome_arquivo})'
plt.title(titulo_grafico)

# Define o nome do arquivo de saída
nome_arquivo_entrada, extensao_arquivo = os.path.splitext(args.csv_file)
nome_arquivo_saida = nome_arquivo_entrada + '_grafico.png'

# Salva o gráfico como uma imagem PNG
plt.savefig(nome_arquivo_saida)
