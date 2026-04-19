import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

sys.setrecursionlimit(200000)

def main():
    n = int(input())
    p = [0]+[*map(int, input().split())]
    e = [[] for _  in range(n+1)]
    v = [0]+[*map(int, input().split())]
    for i in range(1, n+1):
        if p[i] == -1: root = i
        else: e[p[i]].append(i)
    ans = [0]*n
    def dfs(cur):
        cs = {v[cur]}
        cmex = 0
        for nxt in e[cur]:
            nc, nmex = dfs(nxt)
            if len(nc) > len(cs): cs, nc = nc, cs
            cs.update(nc)
            cmex = max(cmex, nmex)
        while cmex in cs: cmex += 1
        ans[cur-1] = cmex
        return cs, cmex
    dfs(root)
    print('\n'.join(map(str, ans)))
    return
if __name__ == "__main__":
    main()