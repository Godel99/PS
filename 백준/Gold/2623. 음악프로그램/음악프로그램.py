import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from collections import deque

def main():
    n, m = map(int, input().split())
    deg = [0]*(n+1)
    e = [[] for _ in range(n+1)]
    for _ in range(m):
        l, *sn = [*map(int, input().split())]
        for i in range(1, l):
            e[sn[i-1]].append(sn[i])
            deg[sn[i]] += 1
    dq = deque([i for i in range(1, n+1) if deg[i] == 0])
    ans = []
    while dq:
        cur = dq.popleft()
        ans.append(cur)
        for nxt in e[cur]:
            deg[nxt] -= 1
            if deg[nxt] == 0: dq.append(nxt)
    print('\n'.join(map(str, ans)) if len(ans) == n else 0)
    return
if __name__ == "__main__":
    main()