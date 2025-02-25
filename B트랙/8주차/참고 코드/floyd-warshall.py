# https://www.acmicpc.net/problem/11404
import sys
input = sys.stdin.readline
n = int(input().strip())
m = int(input().strip())
graph = [[float('inf') for __ in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    graph[i][i] = 0
for i in range(m):
    v1, v2, value = map(int,input().strip().split())
    graph[v1][v2] = min(graph[v1][v2], value)
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if graph[k][j] != float('inf') and graph[i][k] != float('inf'):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
for i in range(1, n+1):
    for j in range(1, n+1):
        if graph[i][j] == float('inf'):
            print(0, end = ' ')
        else:
            print(graph[i][j], end = ' ')
    print()
