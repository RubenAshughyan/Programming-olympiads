from functools import lru_cache

@lru_cache(maxsize=15)
def fact(n):
    return 1 if n == 0 else fact(n-1) * n

def A(n, k):
    return fact(n) / fact(n - k)

n = 14

def f(n, x):
    return 20 * A(n, n - x)

print(min([(f(n, i), i) for i in range(n+1)]))