import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

dr, dc = (1, -1, 0, 0), (0, 0, 1, -1)
from collections import deque

def main():
    n, m = map(int, input().split())
    k = int(input())
    visited = [[0]*(m+1) for _ in range(n+1)]
    def mark_blocked(r, c, d):
        if d == 0:
            visited[r][c] = 1
            return
        for i in range(d+1):
            j = d-i
            for tr, tc in [(r+i, c+j), (r+i, c-j), (r-i, c+j), (r-i, c-j)]:
                if 1 <= tr <= n and 1 <= tc <= m: visited[tr][tc] = 1
    for i in range(k):
        r, c, d = map(int, input().split())
        mark_blocked(r, c, d)
    dq = deque([(1, 1, 0)])
    visited[1][1] = 1
    while dq:
        r, c, d = dq.popleft()
        if r == n and c == m:
            print(f'YES\n{d}')
            return
        for dir in range(4):
            nr, nc = r+dr[dir], c+dc[dir]
            if 1 <= nr <= n and 1 <= nc <= m and not visited[nr][nc]:
                visited[nr][nc] = 1
                dq.append((nr, nc, d+1))
    print('NO')
    return
if __name__ == '__main__':
    main()