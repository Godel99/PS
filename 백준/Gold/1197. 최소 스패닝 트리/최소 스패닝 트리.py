import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    v, e = map(int, input().split())
    edge = []
    for _ in range(e):
        x, y, z = map(int, input().split())
        edge.append((z, x, y))
    edge.sort()
    par = [-1]*(v+1)
    def find(x):
        if par[x] < 0: return x
        par[x] = find(par[x])
        return par[x]
    def unite(x, y):
        x, y = find(x), find(y)
        if x == y: return False
        if par[x] > par[y]: x, y = y, x
        par[x] += par[y]
        par[y] = x
        return True
    ans = cnt = 0
    for z, x, y in edge:
        if find(x) != find(y):
            unite(x, y)
            ans += z
            cnt += 1
            if cnt == v-1: break
    print(ans)
    return
if __name__ == "__main__":
    main()