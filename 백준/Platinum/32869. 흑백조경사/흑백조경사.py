import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

sys.setrecursionlimit(300000)

def main():
    n = int(input())
    e = [[] for _ in range(n+1)]
    c = [0]
    tw = tb = 0
    isEven = [0]*(n+1)
    w, b, cnt = [0]*(n+1), [0]*(n+1), [0]*(n+1)
    ans = []
    for i in [*map(int, input().split())]:
        c.append(i)
        if i: tb += 1
        else: tw += 1
    for _ in range(n-1):
        u, v = map(int, input().split())
        e[u].append(v)
        e[v].append(u)
    def dfs(cur, pre):
        isEven[cur] = 1
        if c[cur]: b[cur] = 1
        else: w[cur] = 1
        for nxt in e[cur]:
            if pre == nxt: continue
            dfs(nxt, cur)
            b[cur] += b[nxt]
            w[cur] += w[nxt]
            isEven[cur] &= isEven[nxt]
            if not isEven[nxt]: cnt[cur] += 1
        if c[cur] and (w[cur] >= b[cur]) or not c[cur] and (b[cur] >= w[cur]): isEven[cur] = 0
    def sol(cur, pre):
        if not cnt[cur] and (c[cur] and (tw < tb) or not c[cur] and (tb < tw)): ans.append(cur)
        if cnt[cur] >= 2: return
        for nxt in e[cur]:
            if nxt == pre: continue
            if cnt[cur] and isEven[nxt]: continue
            if c[cur] and (tw-w[nxt] >= tb-b[nxt]) or not c[cur] and (tb-b[nxt] >= tw-w[nxt]): continue
            sol(nxt, cur)
    dfs(1, 1)
    sol(1, 1)
    ans.sort()
    print(len(ans))
    print(*ans)
    return
if __name__ == "__main__":
    main()