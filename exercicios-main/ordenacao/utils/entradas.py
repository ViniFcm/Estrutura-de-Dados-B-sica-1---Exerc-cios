import random
import string

# Gera 1 milhão de strings aleatórias
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