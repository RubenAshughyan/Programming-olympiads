import math
n = int(input())

class Node:
    mapping = {}
    ws = []
    last_layer = 1
    index = n + 1

    def __init__(self, Nmask, layer=1, is_not=False):
        if isinstance(Nmask, int):
            ind = Nmask
            Nmask = ((ind, 1), )
        if isinstance(Nmask, list):
            Nmask = tuple(Nmask)
        self.layer = layer
        self.Nmask = Nmask
        self.mapping[Nmask] = self
        if is_not:
            Node.last_layer = max(self.last_layer, self.layer)
        else:
            self.add_not(self.not_mask())

    def add_not(self, Nmask):
        node = Node(Nmask, layer=self.layer+1, is_not=True)
        print(self, node, 'not')
        self.ws.append([self, node, -1000])

    def not_mask(self):
        if len(self.Nmask) != 1:
            return tuple(['not'] + list(self.Nmask))
        else:
            return ((self.Nmask[0][0], 0), )

    def get_not(self):
        return self.mapping[self.not_mask()]

    def add_and(self, other):
        assert self.Nmask[0] != 'not'
        assert other.Nmask[0] != 'not'
        print(self, other)
        next_mask = sorted(list(self.Nmask) + list(other.Nmask))
        next_node = Node(next_mask, layer=max(self.layer, other.layer) + 1)
        print(next_node)
        self.ws.append([self.get_not(), next_node, -1000])
        self.ws.append([other.get_not(), next_node, -1000])

    def reindex(self):
        if self.layer == 1:
            self.ind = self.Nmask[0][0]
        else:
            self.ind = Node.index
            Node.index += 1

    def value(self, inpt):
        if self.layer == 1:
            return inpt[self.Nmask[0][0] - 1]
        exps = [n1.value(inpt) * w for (n1, n2, w) in self.ws if n2 == self]
        print(exps)
        exp = -sum(exps)
        if exp < -50:
            e = 0
        elif exp > 50:
            e = float('inf')
        else:
            e = math.exp(exp)
        return 1 / (1 + e)

    def __repr__(self):
        return str(self.Nmask)


def get_node_ind(ind, sz, pref=0):
    inds = []
    for i in range(sz):
        inds.append((i + 1, ind%2))
        ind //= 2
    return tuple([(i+pref, j) for i, j in inds])

def get_node_val(ind):
    return mask[ind]

def construct(m, pref):
    if m % 2:
        construct(m - 1, pref)
        for i in range(2 ** (m - 1)):
            print('add node 1')
            Node.mapping[get_node_ind(i, m - 1, pref)].add_and(Node.mapping[((m+pref, 1), )])
            Node.mapping[get_node_ind(i, m - 1, pref)].add_and(Node.mapping[((m+pref, 0), )])
        return
    mod = 2 ** (m // 2)
    for i in range(2 ** m):
        a = get_node_ind(i % mod, m // 2, pref)
        b = get_node_ind(i // mod, m // 2, pref+m//2)
        print('add node 2')

        Node.mapping[a].add_and(Node.mapping[b])


def add_level(m, pref=0):
    if m == 1:
        return
    add_level(m // 2, pref=pref)
    add_level(m // 2, pref=pref+m//2)
    construct(m, pref)



mask = input()
inputs = [Node(i + 1) for i in range(n)]
add_level(n)

lasts = [(Node.mapping[get_node_ind(i, n)], get_node_val(i)) for i in range(2 ** n)]

last_node = Node(100000000, layer=Node.last_layer+1, is_not=True)
print(last_node)
for last, val in lasts:
    w = -1000 if val == '0' else 1000
    Node.ws.append([last, last_node, w])

print(*Node.mapping.values(), sep='\n')
print(*Node.ws, sep='\n')
for t in range(1000):
    x = list(map(int, input()))
    print(last_node.value(x))

for node in Node.mapping.values():
    node.reindex()

nodes = sorted(Node.mapping.values(), key=lambda node: node.ind)
# print(max([node.layer for node in nodes]), len(nodes))
# print(*[node.layer for node in nodes])
# print(len(Node.ws))
# for n1, n2, w in Node.ws:
#     print(n1.ind, n2.ind, w)
