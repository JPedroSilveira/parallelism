import random
import string
import pexpect
import time

def generate_random_string(length):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

# Número de strings desejado
num_strings = 200

# Comprimento máximo para cada string
max_length = 10

# Gerar as N strings 
string_list = [generate_random_string(random.randint(1, max_length)) for _ in range(num_strings)]

p = pexpect.spawn('./shsup_parallel', timeout=None)

start_time = time.time()

p.sendline(str(num_strings))

for i in range(0, num_strings):
    p.sendline(string_list[i])

print(p.read())

print("--- %s seconds ---" % (time.time() - start_time))

p.close()