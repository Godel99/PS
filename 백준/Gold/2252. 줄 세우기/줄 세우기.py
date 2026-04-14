import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from collections import deque

def main():
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    deg = [0]*(n+1)
    for _ in range(m):
        u, v = map(int, input().split())
        e[u].append(v)
        deg[v] += 1
    dq = deque()
    for i in range(1, n+1):
        if deg[i] == 0: dq.append(i)
    while dq:
        cur = dq.popleft()
        print(cur, end=' ')
        for nxt in e[cur]:
            deg[nxt] -= 1
            if deg[nxt] == 0: dq.append(nxt)
    return
if __name__ == "__main__":
    main()