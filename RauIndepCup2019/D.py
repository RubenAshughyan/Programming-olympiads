n = list(input())


for i in range(len(n)-3):
    if n[i] == '?':
        n[i] = '1' if i==0 else '0'

mn = -1

for i in range(1000):
    x, y, z = i//100, (i//10)%10, i%10
    n1 = n[:]
    if len(n) > 2 and n[-3] == '?':
        n1[-3] = str(x)
    if len(n) > 1 and n[-2] == '?':
        n1[-2] = str(y)
    if len(n) and n[-1] == '?':
        n1[-1] = str(z)
    q = int(''.join(n1))
    if ''.join(n1)[0]=='0':
        continue
    if q % 8 == 0:
        if mn == -1 or mn > q:
            mn = q
            
print(mn)
        
    
