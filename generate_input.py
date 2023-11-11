import random
import string

def generate_random_string(length):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

# Número de strings desejado
num_strings = 200

# Comprimento máximo para cada string
max_length = 10

# Gerar as 200 strings
string_list = [generate_random_string(random.randint(1, max_length)) for _ in range(num_strings)]

# Imprimir as strings
for i, string in enumerate(string_list, 1):
    print(f"{string}")