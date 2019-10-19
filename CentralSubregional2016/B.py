k = int(input())
k = k // 3
answer = 2**(2*k-1) + (2**(k-1+k%2) - 1) - (k%2)
print(answer)