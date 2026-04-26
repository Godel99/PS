import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

import heapq

def main():
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    deg = [0]*(n+1)
    for _ in range(m):
        u, v = map(int, input().split())
        e[u].append(v)
        deg[v] += 1
    hq = []
    for i in range(1, n+1):
        if not deg[i]: heapq.heappush(hq, i)
    ans = []
    while hq:
        cur = heapq.heappop(hq)
        ans.append(cur)
        for nxt in e[cur]:
            deg[nxt] -= 1
            if not deg[nxt]: heapq.heappush(hq, nxt)
    print(*ans)  
    return
if __name__ == "__main__":
    main()