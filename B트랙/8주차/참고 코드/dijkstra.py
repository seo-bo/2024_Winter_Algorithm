# https://www.acmicpc.net/problem/1916
import sys
from collections import defaultdict
from heapq import heappush, heappop
input = sys.stdin.readline
n = int(input().strip())
m = int(input().strip())
graph = defaultdict(list)
for i in range(m):
    v1, v2, cost = map(int, input().strip().split())
    graph[v1].append((v2, cost))
start, end = map(int,input().strip().split())
dist = [float('inf') for _ in range(n+1)]
dist[start] = 0
pq = []
heappush(pq,(0,start))
while pq:
    cur_value, cur_ver = heappop(pq)
    if dist[cur_ver] < cur_value:
        continue
    for nxt_ver, weight in graph[cur_ver]:
        if dist[nxt_ver] > cur_value + weight:
            dist[nxt_ver] = cur_value + weight
            heappush(pq,(dist[nxt_ver],nxt_ver))
print(dist[end])
