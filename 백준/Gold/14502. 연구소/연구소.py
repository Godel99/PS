import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from itertools import combinations
dx, dy = (1, -1, 0, 0), (0, 0, 1, -1)
from collections import deque

def main():
    n, m = map(int, input().split())
    lab = [list(map(int, input().split())) for _ in range(n)]
    ety, vir = [], [] 
    for i in range(n):
        for j in range(m):
            if lab[i][j] == 2: vir.append((i, j))
            elif lab[i][j] == 0: ety.append((i, j))
    def safe(wall):
        for x, y in wall: lab[x][y] = 1
        vis = [[0]*m for _ in range(n)]
        dq = deque(vir)
        for x, y in vir: vis[x][y] = 1
        cnt = 0
        while dq:
            x, y = dq.popleft()
            for dir in range(4):
                nx, ny = x+dx[dir], y+dy[dir]
                if 0 <= nx < n and 0 <= ny < m and not lab[nx][ny] and not vis[nx][ny]:
                    vis[nx][ny] = 1
                    cnt += 1
                    dq.append((nx, ny))
        for x, y in wall: lab[x][y] = 0
        return len(ety)-cnt-3
    ans = 0
    for wall in combinations(ety, 3): ans = max(ans, safe(wall))
    print(ans)
    return  
if __name__ == '__main__':
    main()