def is_prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

def next_prim():
    a = 2
    while True:
        yield a
        a += 1
        while not is_prime(a):
            a += 1

def generate():
    prim = next_prim()
    while True:
        a = next(prim)
        b = 2**a - 1
        while not is_prime(b):
            a = next(prim)
            b = 2**a - 1
        yield b


gene = generate()
x = int(input())
for i in range(x - 1):
    next(gene)

print(next(gene))
