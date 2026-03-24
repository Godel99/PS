import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

sys.setrecursionlimit(10**5)

def main():
    n = int(input())
    e = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
        e[v].append((u, w))
    def dfs(cur, pre):
        node, d = cur, 0
        for nxt, nd in e[cur]:
            if nxt == pre: continue
            nnode, nnd = dfs(nxt, cur)
            nnd += nd
            if nnd > d: d, node = nnd, nnode
        return node, d
    print(dfs(dfs(1, 0)[0], 0)[1])
    return
if __name__ == '__main__':
    main()