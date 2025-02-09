# https://www.acmicpc.net/problem/25516
import sys
from collections import defaultdict
input = sys.stdin.readline

def dfs(node, limit, distance, graph, apple, visited):
    visited[node] = True
    cnt = apple[node]
    if distance + 1 <= limit:
        for nxt in graph[node]:
            if not visited[nxt]:
                cnt += dfs(nxt, limit, distance + 1, graph, apple, visited)
    return cnt

vertex, dist = map(int, input().strip().split())
sys.setrecursionlimit(vertex+300)
graph = defaultdict(list)
for _ in range(vertex - 1):
    v1, v2 = map(int, input().strip().split())
    graph[v1].append(v2)
    graph[v2].append(v1)
apple = list(map(int, input().strip().split()))
visited = [False] * vertex
result = dfs(0, dist, 0, graph, apple, visited)
print(result)
