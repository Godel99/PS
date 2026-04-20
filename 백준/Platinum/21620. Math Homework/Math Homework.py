import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

sys.setrecursionlimit(200000)
from math import gcd, lcm

def main():
    n, m = map(int, input().split())
    tree, lazy = [1]*(n*4+1), [1]*(n*4+1)
    def init(cur, l, r):
        mid = (l + r) >> 1
        if l != r:
            init(cur<<1, l, mid)
            init(cur<<1|1, mid+1, r)
    def prop(cur, l, r):
        if lazy[cur] == 1: return
        if l != r:
            lazy[cur<<1] = lcm(lazy[cur], lazy[cur<<1])
            lazy[cur<<1|1] = lcm(lazy[cur], lazy[cur<<1|1])
        tree[cur] = lcm(tree[cur], lazy[cur])
    def upd(cur, l, r, L, R, g):
        prop(cur, l, r)
        if L > r or l > R: return
        if L <= l and r <= R:
            lazy[cur] = g
            prop(cur, l, r)
            return
        mid = (l + r) >> 1
        upd(cur<<1, l, mid, L, R, g)
        upd(cur<<1|1, mid+1, r, L, R, g)
        tree[cur] = gcd(tree[cur<<1], tree[cur<<1|1])
    def qry(cur, l, r, L, R):
        prop(cur, l, r)
        if l > R or L > r: return 0
        if L <= l and r <= R: return tree[cur]
        mid = (l + r) >> 1
        return gcd(qry(cur<<1, l, mid, L, R), qry(cur<<1|1, mid+1, r, L, R))
    init(1, 1, n)
    q = []
    for _ in range(m):
        l, r, g = map(int, input().split())
        upd(1, 1, n, l, r, g)
        q.append((l, r, g))
    for l, r, g in q:
        if qry(1, 1, n, l, r) != g: print('Impossible'); return
    ans = []
    def push(cur, l, r):
        prop(cur, l, r)
        if l == r:
            ans.append(tree[cur])
            return
        mid = (l + r) >> 1
        push(cur<<1, l, mid)
        push(cur<<1|1, mid+1, r)
    push(1, 1, n)
    print(*ans)
    return
if __name__ == "__main__":
    main()