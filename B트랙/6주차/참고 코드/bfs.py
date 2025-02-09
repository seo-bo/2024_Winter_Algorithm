#https://www.acmicpc.net/problem/18352
import sys
from collections import defaultdict, deque
input = sys.stdin.readline

def bfs():
    visited = [False for _ in range(vertex + 1)]
    answer = []
    q = deque()
    visited[start] = True
    q.append((start, 0))
    while q:
        current, cnt = q.popleft()
        if cnt == dist:
            answer.append(current)
            continue
        for nxt in graph[current]:
            if not visited[nxt]:
                visited[nxt] = True
                q.append((nxt, cnt + 1))
    answer.sort()
    return answer

vertex, edge, dist, start = map(int, input().strip().split())
graph = defaultdict(list)
for i in range(edge):
    v1, v2 = map(int, input().strip().split())
    graph[v1].append(v2)
ans = bfs()
if ans:
    print("\n".join(map(str, ans)))
else:
    print(-1)
