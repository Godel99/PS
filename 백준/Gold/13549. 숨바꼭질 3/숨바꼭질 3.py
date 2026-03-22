import sys

def f(n, k):
    if n >= k: return n - k
    if k == 1: return abs(n - 1)
    
    if k % 2:
        return 1 + min(f(n, k + 1), f(n, k - 1))
    else:
        return min(k - n, f(n, k // 2))
n, m = map(int, sys.stdin.readline().split())
print(f(n, m))