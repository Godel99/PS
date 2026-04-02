import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

import heapq
from math import inf

def main():
    n, m, r = map(int, input().split())
    e = [[] for _ in range(n+1)]
    t = list(map(int, input().split()))
    for _ in range(r):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
        e[v].append((u, w))
    def dji(start):
        dist = [inf]*(n+1)
        dist[start] = 0
        hq = [(0, start)]
        while hq:
            d, cur = heapq.heappop(hq)
            if d > m: break
            if dist[cur] < d: continue
            for nxt, nd in e[cur]:
                cost = d+nd
                if dist[nxt] > cost and m >= cost:
                    dist[nxt] = cost
                    heapq.heappush(hq, (cost, nxt))
        return sum(t[i-1] for i in range(1, n+1) if dist[i] <= m)
    ans = 0
    for i in range(1, n+1): ans = max(ans, dji(i))
    print(ans)
    return  
if __name__ == '__main__':
    main()