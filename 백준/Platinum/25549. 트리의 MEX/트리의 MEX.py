import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

sys.setrecursionlimit(200000)

def main():
    n = int(input())
    p = [0]+[*map(int, input().split())]
    e = [[] for _  in range(n+1)]
    s = [set() for _ in range(n+1)]
    v = [0]+[*map(int, input().split())]
    root = -1
    for i in range(1, n+1):
        if p[i] == -1: root = i
        else:e[p[i]].append(i)
    ans = [0]*n
    def dfs(cur):
        s[cur].add(v[cur])
        prv = 0
        for nxt in e[cur]:
            dfs(nxt)
            prv = max(prv, ans[nxt-1])
            if len(s[nxt]) > len(s[cur]): s[cur], s[nxt] = s[nxt], s[cur]
            s[cur].update(s[nxt])
            s[nxt].clear()
        while prv in s[cur]: prv += 1
        ans[cur-1] = prv
    dfs(root)
    print('\n'.join(map(str, ans)))
    return
if __name__ == "__main__":
    main()