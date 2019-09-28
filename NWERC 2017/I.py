n, c = map(int, input().split())

spaces = [list(map(int, input().split())) for i in range(n)]
spaces = [[s, -d, i] for i, (d, s) in enumerate(spaces)]

spaces.sort()

cc = c
for s, d, i in spaces:
	if s <= cc:
		cc -= s
	else:
		i -= 1
		break
else:
	i = None

anss = []

if i is not None:
	for s, d, ind in spaces[i:]:
		if s > cc:
			break
		if -d <= c:
			anss.append(ind + 1)
			break
for s, d, ind in spaces[:i]:
	anss.append(ind + 1)
	
print(len(anss))
if anss:
	print(*anss)