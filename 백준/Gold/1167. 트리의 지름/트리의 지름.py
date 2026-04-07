import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

sys.setrecursionlimit(10**6)

def main():
    v = int(input())
    e = [[] for _ in range(v+1)]
    for _ in range(v):
        data = [*map(int, input().split())]
        for i in range(1, len(data)-1, 2): e[data[0]].append((data[i], data[i+1]))
    def dfs(cur, pre):
        node, d = cur, 0
        for nxt, nd in e[cur]:
            if nxt == pre: continue
            nnde, nnd = dfs(nxt, cur)
            nnd += nd
            if nnd > d: d, node = nnd, nnde
        return node, d
    print(dfs(dfs(1, 0)[0], 0)[1])
    return  
if __name__ == '__main__':
    main()