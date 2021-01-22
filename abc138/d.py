n, q = list(map(int, input().split()))
edge = []
for i in range(n-1):
    tempa, tempb = list(map(int, input().split()))
    edge.append((tempa-1, tempb-1))

node = [0] * n

for i in range(q):
    p, x = list(map(int, input().split()))
    node[p-1] += x

edge.sort()
for e in edge:
    node[e[1]] += node[e[0]]

for n in node:
    print(n)
