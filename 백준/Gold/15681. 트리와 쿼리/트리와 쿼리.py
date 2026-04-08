import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

sys.setrecursionlimit(10**7)

def main():
    n, r, q = map(int, input().split())
    e = [[] for _ in range(n+1)]
    vis = [0]*(n+1)
    subtsize = [0]*(n+1)
    for _ in range(n-1):
        u, v = map(int, input().split())
        e[u].append(v)
        e[v].append(u)
    def dfs(cur):
        vis[cur] = subtsize[cur] = 1
        for nxt in e[cur]:
            if not vis[nxt]:
                dfs(nxt)
                subtsize[cur] += subtsize[nxt]                        
    dfs(r)
    ans = []
    for _ in range(q):
        qry = int(input())
        ans.append(subtsize[qry])
    print('\n'.join(map(str, ans)))
    return
if __name__ == "__main__":
    main()