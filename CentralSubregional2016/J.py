def get_parts(s):
    return sum(s[:3]), sum(s[3:])

n, m = map(int, input().split())
b = list(map(get_parts, input().split()))
t = list(map(get_parts, input().split()))

cb = {}
ct = {}

for i in b:
    if i[0] in cb:
