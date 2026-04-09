import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n, m = map(int, input().split())
    e = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        e.append((w, u, v))
    e.sort()
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
    maxw = sumw = cnt = 0
    for w, u, v, in e:
        if find(u) != find(v):
            unite(u, v)
            sumw += w
            maxw = w
            cnt += 1
        if cnt == n-1: break
    print(sumw-maxw)
    return
if __name__ == "__main__":
    main()