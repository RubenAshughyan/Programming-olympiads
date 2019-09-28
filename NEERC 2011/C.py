m = int(input())
s1 = [input() for i in range(m)]
print('done 1')
s2 = [input() for i in range(m)]

c = 0
for i in range(m):
    for j in range(len(s1[i])):
        c += (s1[i][j] != s2[i][j])

print(c)

