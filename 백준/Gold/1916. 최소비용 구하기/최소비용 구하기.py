import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from math import inf
import heapq

def main():
    n = int(input())
    m = int(input())
    dp = [inf]*(n+1)
    e = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        e[u].append((v, w))
    start, end = map(int, input().split())
    dp[start] = 0
    hq = []
    heapq.heappush(hq, (0, start))
    while hq:
        cost, cur = heapq.heappop(hq)
        if dp[cur] < cost: continue
        for nxt, ncost in e[cur]:
            if dp[nxt] > cost+ncost: 
                dp[nxt] = cost+ncost
                heapq.heappush(hq, (dp[nxt], nxt))
    print(dp[end])
if __name__ == '__main__':
    main()