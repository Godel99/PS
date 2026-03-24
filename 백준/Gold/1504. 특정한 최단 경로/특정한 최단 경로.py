import sys 
import heapq
from math import inf

# 최적화된 I/O
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
        e[v].append((u, w))
    v1, v2 = map(int, input().split())

    def dij(start):
        dist = [inf] * (n + 1)
        dist[start] = 0
        hq = [(0, start)]
        h_push, h_pop = heapq.heappush, heapq.heappop # 지역 변수화
        
        while hq:
            w, cur = h_pop(hq)
            if dist[cur] < w: continue
            for nxt, nw in e[cur]:
                if dist[nxt] > w + nw:
                    dist[nxt] = w + nw
                    h_push(hq, (dist[nxt], nxt))
        return dist

    # 다익스트라 2회로 최적화
    distv1 = dij(v1)
    distv2 = dij(v2)

    # 무방향 그래프의 대칭성 활용
    path1 = distv1[1] + distv1[v2] + distv2[n]
    path2 = distv2[1] + distv2[v1] + distv1[n]

    ans = min(path1, path2)
    print(-1 if ans >= inf else ans)

if __name__ == '__main__':
    main()