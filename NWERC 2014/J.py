from collections import Counter

n = int(input())

c1 = Counter([input() for i in range(n)])
c2 = Counter([input() for i in range(n)])

s=0
for k, v in c1.items():
    s+=min(c2[k], v)
print(s)