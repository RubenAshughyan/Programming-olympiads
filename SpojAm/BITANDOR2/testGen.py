import random

n = random.randint(1,8)
k = random.randint(1,n)

a = []
for i in range(n):
    a.append(str(random.randint(1,60)))

print('%d %d'%(n,k))
print(' '.join(a))
