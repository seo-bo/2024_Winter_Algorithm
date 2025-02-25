# https://www.acmicpc.net/problem/11657
import sys
from collections import defaultdict
input = sys.stdin.readline
n,m = map(int,input().strip().split())
graph = defaultdict(list)
for i in range(m):
    v1, v2, value = map(int,input().strip().split())
    graph[v1].append((v2,value))
dist = [float('inf') for _ in range(n+1)]
dist[1] = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        for v, cost in graph[j]:
            if dist[j] != float('inf') and dist[v] > dist[j] + cost:
                dist[v] = dist[j] + cost
                if i == n:
                    print(-1)
                    sys.exit()
for i in range(2, n+1):
    if dist[i] == float('inf'):
        print(-1)
    else:
        print(dist[i])
