import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n, m = map(int, input().split())
    if n == 2: print(0); return
    e = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        e.append((u, v, w))
    e.sort(key=lambda x: x[2])
    par = [-1]*(n+1)
    def find(x):
        if par[x] < 0: return x
        par[x] = find(par[x])
        return par[x]
    def unite(x, y):
        x, y = find(x), find(y)
        if x == y: return
        if par[x] > par[y]: x, y = y, x
        par[x] += par[y]
        par[y] = x
    ans = cnt = 0
    for u, v, w in e:
        if find(u) != find(v):
            unite(u, v)
            ans += w
            cnt += 1
        if cnt == n-2: break
    print(ans)
    return
if __name__ == "__main__":
    main()