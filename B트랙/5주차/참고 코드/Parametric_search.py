#https://www.acmicpc.net/problem/2805
import sys
input = sys.stdin.readline
n,m = map(int,input().strip().split())
v = list(map(int,input().strip().split()))
left, right, ans = 0 , max(v), 0
while left <= right:
    mid = (left + right) // 2
    pivot = 0
    for i in v:
        pivot += max(0, i - mid)
    if pivot >= m:
        ans = mid
        left = mid + 1
    else:
        right = mid - 1
print(ans)
