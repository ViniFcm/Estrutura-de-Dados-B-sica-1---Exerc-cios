import random
import string
import os

# Garante que a pasta "data/" existe
os.makedirs('data', exist_ok=True)

# Gera 1 milhão de strings aleatórias únicas
strings = []
for _ in range(1_000_000):
    tamanho = random.randint(5, 10)
    s = ''.join(random.choices(string.ascii_lowercase, k=tamanho))
    strings.append(s)

# Arquivo 1: aleatório
with open('data/entrada_aleatoria.txt', 'w') as f:
    for s in strings:
        f.write(s + ' ')

# Arquivo 2: crescente
strings.sort()
with open('data/entrada_crescente.txt', 'w') as f:
    for s in strings:
        f.write(s + ' ')

# Arquivo 3: decrescente
strings.sort(reverse=True)
with open('data/entrada_decrescente.txt', 'w') as f:
    for s in strings:
        f.write(s + ' ')

# Arquivo 4: muitas repetições, ordem aleatória
# Gera uma pequena lista de palavras base
palavras_base = [
    ''.join(random.choices(string.ascii_lowercase, k=random.randint(5, 10)))
    for _ in range(100)  # apenas 100 palavras distintas
]

# Cria uma lista de 1 milhão de palavras com muitas repetições
strings_repetidas = [random.choice(palavras_base) for _ in range(1_000_000)]
random.shuffle(strings_repetidas)

with open('data/entrada_muitas_repetidas.txt', 'w') as f:
    for s in strings_repetidas:
        f.write(s + ' ')