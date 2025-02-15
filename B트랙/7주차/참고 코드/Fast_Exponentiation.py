import sys, math
input = sys.stdin.readline

def power(n,exp):
    if exp == 0:
        return 1
    mid = power(n, exp // 2)
    return mid * mid if exp % 2 == 0 else mid * mid * n

n,exp = map(int,input().strip().split())
sys.setrecursionlimit(int(math.log2(exp)) + 100)
print(power(n,exp))
