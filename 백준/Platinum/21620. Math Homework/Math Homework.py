import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import gcd, lcm

def main():
    n, m = map(int, input().split())
    qry = []
    d = [[0]*(n+2) for _ in range(17)]
    for _ in range(m):
        x, y, z =  map(int, input().split())
        qry.append((x, y, z))
        d[z][x] += 1
        d[z][y+1] -= 1
    ans = [1]*(n+1)
    for z in range(1, 17):
        cnt = 0
        for i in range(1, n+1):
            cnt += d[z][i]
            if cnt > 0:
                ans[i] = lcm(ans[i], z)
    tree = [0]*2*n
    for i in range(n): tree[n+i] = ans[i+1]
    for i in range(n-1, 0, -1): tree[i] = gcd(tree[i<<1], tree[i<<1|1])
    for x, y, z in qry:
        res = 0
        l, r = x+n-1, y+n-1
        while l <= r:
            if l&1:
                res = gcd(res, tree[l])
                l += 1
            if ~r&1:
                res = gcd(res, tree[r])
                r -= 1
            l >>= 1
            r >>= 1
        if res != z: print('Impossible'); return
    print(*ans[1:])
    return
if __name__ == "__main__":
    main()