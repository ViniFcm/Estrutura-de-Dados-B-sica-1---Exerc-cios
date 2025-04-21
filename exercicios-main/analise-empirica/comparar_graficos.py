import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import sys
import os

# Verificar se dois arquivos foram passados como argumento
if len(sys.argv) < 3:
    print("Por favor, forneça dois arquivos CSV como argumento.")
    sys.exit(1)

# Caminho dos arquivos CSV fornecidos pela linha de comando
csv_file1 = sys.argv[1]
csv_file2 = sys.argv[2]

# Remover a extensão .csv dos nomes dos arquivos
file1_name = os.path.splitext(os.path.basename(csv_file1))[0]
file2_name = os.path.splitext(os.path.basename(csv_file2))[0]

# Nome do arquivo de saída
output_filename = f"Comparacao_{file1_name}_{file2_name}.png"

# Carregar os arquivos CSV
try:
    df1 = pd.read_csv(csv_file1, header=None, names=["tamanho", "tempo"])
    df2 = pd.read_csv(csv_file2, header=None, names=["tamanho", "tempo"])
except FileNotFoundError as e:
    print(f"Erro ao abrir um dos arquivos: {e}")
    sys.exit(1)

# Função para calcular a linha de tendência
def plot_trend_line(x, y, color, label):
    # Calcula os coeficientes da linha de tendência (regressão linear)
    z = np.polyfit(x, y, 1)
    p = np.poly1d(z)
    
    # Plotar a linha de tendência
    plt.plot(x, p(x), label=label, color=color, linewidth=2)

# Plotar as medições individuais como círculos para o primeiro arquivo
plt.scatter(df1['tamanho'], df1['tempo'], label=f'Medições Individuais - {csv_file1}', color='blue', s=100, alpha=0.15)

# Plotar a linha de tendência para o primeiro arquivo
plot_trend_line(df1['tamanho'], df1['tempo'], 'black', f'Tendência - {csv_file1}')

# Plotar as medições individuais como círculos para o segundo arquivo
plt.scatter(df2['tamanho'], df2['tempo'], label=f'Medições Individuais - {csv_file2}', color='red', s=100, alpha=0.15)

# Plotar a linha de tendência para o segundo arquivo
plot_trend_line(df2['tamanho'], df2['tempo'], 'black', f'Tendência - {csv_file2}')

# Configurações do gráfico
plt.title('Comparação dos Tempos de Execução com Linha de Tendência')
plt.xlabel('Tamanho do Array')
plt.ylabel('Tempo de Execução (nanosegundos)')
plt.legend()

# Salvar o gráfico como arquivo PNG
plt.savefig(output_filename)

# Exibir mensagem de sucesso
print(f"Gráfico salvo como {output_filename}")
