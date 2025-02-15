# https://www.acmicpc.net/problem/15649
import sys
input = sys.stdin.readline

def dfs(depth, num, limit):
    if depth == limit:
        print(' '.join(map(str,ary)))
        return
    for i in range(1, num+1):
        if visited[i]:
            continue
        visited[i] = True
        ary.append(i)
        dfs(depth+1,num,limit)
        ary.pop()
        visited[i] = False

n,m = map(int,input().strip().split())
sys.setrecursionlimit(m + 10)
visited = [False for _ in range(n+1)]
ary = []
dfs(0,n,m)
