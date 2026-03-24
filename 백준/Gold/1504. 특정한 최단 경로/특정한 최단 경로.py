import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

import heapq
from math import inf

def main():
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
        e[v].append((u, w))
    v1, v2 = map(int, input().split())
    def dij(start):
        dist = [inf]*(n+1)
        dist[start] = 0
        hq = [(0, start)]
        while hq:
            w, cur = heapq.heappop(hq)
            if dist[cur] < w: continue
            for nxt, nw in e[cur]:
                if dist[nxt] > w+nw:
                    dist[nxt] = w+nw
                    heapq.heappush(hq, (dist[nxt], nxt))           
        return dist
    distv1, distv2 = dij(v1), dij(v2)
    path1 = distv1[1]+distv1[v2]+distv2[n]
    path2 = distv2[1]+distv2[v1]+distv1[n]
    ans = min(path1, path2)
    print(-1 if ans == inf else ans)
    return
if __name__ == '__main__':
    main()