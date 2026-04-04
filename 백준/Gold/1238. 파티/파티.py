import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

import heapq
from math import inf

def main():
    n, m, x = map(int, input().split())
    e = [[] for _ in range(n+1)]
    re = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
        re[v].append((u, w))
    def dji(start, e):
        dist = [inf]*(n+1)
        hq = [(0, start)]
        dist[start] = 0
        while hq:
            d, cur = heapq.heappop(hq)
            if dist[cur] < d: continue
            for nxt, nd, in e[cur]:
                if dist[nxt] > d+nd:
                    dist[nxt] = d+nd
                    heapq.heappush(hq, (dist[nxt], nxt))
        return dist
    go = dji(x, e)
    come = dji(x, re)
    ans = 0
    for i in range(1, n+1):
        if go[i] != inf and come[i] != inf: ans = max(ans, go[i]+come[i])
    print(ans)
    return  
if __name__ == '__main__':
    main()