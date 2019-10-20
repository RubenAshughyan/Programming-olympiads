n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
index = a.index(max(a))

A = a[index] + n - 1
B = sum(a)
aa = index
bb = sum(a[:index])

if k - aa >= 0 and (k - bb + B - 1) // B <= (k - aa) // A:
    print("YES")
else:
    print("KEK")