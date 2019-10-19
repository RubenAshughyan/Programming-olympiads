from functools import reduce
print(reduce(lambda x, y: x * y, ([8] + [9] * 8 + [10] * 300)[:int(input())], 1))