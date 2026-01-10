import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

import heapq
INF = int(1e9)

def dijkstra(s, n, g):
    dist = [INF] * (n+1)
    dist[s] = 0
    pq = [(0, s)]
    while pq:
        cost, cur = heapq.heappop(pq)
        if cost > dist[cur]: continue
        for nxt, w in g[cur]:
            if dist[nxt] > cost+w:
                dist[nxt] = cost+w
                heapq.heappush(pq, (dist[nxt], nxt))
    return dist

def solution(n, s, a, b, fares):
    graph = [[] for _ in range(n+1)]
    for u, v, w in fares:
        graph[u].append((v, w))
        graph[v].append((u, w))
    distS = dijkstra(s, n, graph)
    distA = dijkstra(a, n, graph)
    distB = dijkstra(b, n, graph)
    ans = INF
    for k in range(1, n+1):
        if distS[k] == INF or distA == INF or distB == INF: continue
        ans = min(ans, distS[k]+distA[k]+distB[k])
    return ans

def main():
    print(solution(6,	4,	6,	2,	[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))
if __name__ == '__main__':
    main()