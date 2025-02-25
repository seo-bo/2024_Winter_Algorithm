# https://www.acmicpc.net/problem/1261
import sys
from collections import deque
input = sys.stdin.readline
m,n = map(int,input().strip().split())
grid = [list(map(int, list(input().strip()))) for _ in range(n)]
visited = [[float('inf')for __ in range(m)] for _ in range(n)]
visited[0][0] = grid[0][0]
dir = [(-1,0),(1,0),(0,-1),(0,1)]
dq = deque()
dq.append((0,0,visited[0][0]))
while dq:
    x,y,value = dq.popleft()
    if x == n - 1 and y == m - 1:
        print(value)
        break
    for i in range(4):
        nx = x + dir[i][0]
        ny = y + dir[i][1]
        if 0 <= nx < n and 0 <= ny < m:
            if visited[nx][ny] > visited[x][y] + grid[nx][ny]:
                visited[nx][ny] = visited[x][y] + grid[nx][ny]
                if grid[nx][ny] == 1:
                    dq.append((nx,ny,visited[nx][ny]))
                else:
                    dq.appendleft((nx,ny,visited[nx][ny]))
