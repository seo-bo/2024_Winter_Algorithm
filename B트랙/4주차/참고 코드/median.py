#https://www.acmicpc.net/problem/1655
import sys
from heapq import heappush, heappop
input = sys.stdin.readline
n = int(input().strip())
max_heap = []
min_heap = []
def balance():
    if not max_heap and not min_heap:
        return
    if min_heap and -max_heap[0] > min_heap[0]:
        mini = -heappop(min_heap)
        maxi = -heappop(max_heap)
        heappush(min_heap,maxi)
        heappush(max_heap,mini)
    if len(max_heap) > len(min_heap) + 1:
        heappush(min_heap,-heappop(max_heap))
for i in range(n):
    a = int(input().strip())
    heappush(max_heap,-a)
    balance()
    print(-max_heap[0])