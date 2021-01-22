from collections import defaultdict
from queue import Queue
n, m = list(map(int, input().split()))
MX = int(1e6)
edge = defaultdict(set)
kenedge = defaultdict(set)
dist = [MX for i in range(n)]
reached = [False for i in range(n)]

for loop in range(m):
    a, b = list(map(int, input().split()))
    edge[a-1].add(b-1)

for i in range(n):
    step1 = set()
    for ii in edge[i]:
        step1 |= edge[ii]
    step2 = set()
    for iii in step1:
        step2 |= edge[iii]
    step3 = set()
    for iiii in step2:
        kenedge[i].add(iiii)

s, t = list(map(int, input().split()))
s = s-1
t = t-1
dist[s] = 0

q = Queue()
q.put(s)
reached[s] = True
while not q.empty():
    node = q.get()
    for next_node in kenedge[node]:
        if reached[next_node]: continue
        reached[next_node] = True
        q.put(next_node)
        dist[next_node] = min(dist[next_node], dist[node] + 1)

if dist[t] == MX:
    print(-1)
else:
    print(dist[t])

