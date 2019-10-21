from functools import lru_cache

n, a = map(int, input().split())

def fact(x):
    return fact(x-1) * x if x else 1

@lru_cache(maxsize=None)
def C(k):
    return fact(n-1) // fact(k) // fact(n-k-1)

s = 0
for i in range(n-1):
    s += C(i)

if s + 1 > a:
    print(-1)
else:
    v = [1] * (n-1)
    v.append(a-s)
    while len(v):
        print(*v)
        for i in range(len(v)-1):
            v[i] += v[i+1]
        v = v[:-1]
