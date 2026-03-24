import sys
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from math import inf

def main():
    n = int(input())
    A = [0]+list(map(int, input().split()))
    T = [0]*(n+1)
    q = int(input())
    ans = [0]*(q+1)
    seg = [inf]*4*n
    lazy = [0]*4*n  
    def update(now, l, r, L, R, x, t):
        if R < l or r < L: return
        if L <= l and r <= R:
            if seg[now] > x:
                seg[now] = x
                lazy[now] = max(lazy[now], t)
            A[L] = seg[now]
            T[L] = lazy[now]
            return
        if seg[now<<1] > seg[now]:
            seg[now<<1] = seg[now]
            lazy[now<<1] = max(lazy[now<<1], lazy[now])
        if seg[now<<1|1] > seg[now]:
            seg[now<<1|1] = seg[now]
            lazy[now<<1|1] = max(lazy[now<<1|1], lazy[now])
        mid = (l+r)>>1
        update(now<<1, l, mid, L, R, x, t)
        update(now<<1|1, mid+1, r, L, R, x, t)
    for i in range(1, n+1): update(1, 1, n, i, i, A[i], 0)
    for i in range(1, q+1):
        l, r, x = map(int, input().split())
        update(1, 1, n, l, r, x, i)
    for i in range(1, n+1):
        update(1, 1, n, i, i, inf, 0)
        print(A[i], end=' ')
        ans[T[i]] += 1
    print()
    for i in range(1, q+1): 
        ans[i] += ans[i-1]
        print(ans[i], end=' ')
    return 0
if __name__ == '__main__':
    sys.exit(main())