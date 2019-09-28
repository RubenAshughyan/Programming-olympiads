n, r, p = map(int, input().split())

mi = None

def f(n, k):
    if n == 1:
        return 0
    if k == 0:
        return r + p * (n - 1)
    m = int(n ** (1 / (k + 1)))
    ret =  min(f((n + m - 1) // m, k - 1) + p * (m - 1), f((n + m) // (m + 1), k - 1) + p * m) + r
    return ret


for k in range(20):
    if mi is None:
        mi = f(n, k)
    else:
        mi = min(f(n, k), mi)
print(mi)