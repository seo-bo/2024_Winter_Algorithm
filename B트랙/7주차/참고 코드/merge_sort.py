import sys
input = sys.stdin.readline

def merge(left,mid,right):
    L = ary[left:mid + 1]
    R = ary[mid+1: right + 1]
    i, j, k = 0, 0, left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            ary[k] = L[i]
            i += 1
        else:
            ary[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        ary[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        ary[k] = R[j]
        j += 1
        k += 1

def merge_sort(left,right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(left, mid)
        merge_sort(mid+1,right)
        merge(left,mid,right)

n = int(input().strip())
sys.setrecursionlimit(n+100)
ary = list(map(int,input().strip().split()))
merge_sort(0,n-1)
print(' '.join(map(str,ary)))
