import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque
from math import inf

def main():
    n = int(input())
    board = []
    size = 2
    time = 0
    eat = 0
    for i in range(n):
        row = [*map(int, input().split())]
        board.append(row)
        for j in range(n):
            if row[j] == 9: 
                x, y = i, j
                board[i][j] = 0
    def getfish(x, y, size):
        dist = [[-1]*n for _ in [0]*n]
        dq = deque([(x, y)])
        dist[x][y] = 0
        can = []
        mind = inf
        while dq:
            rx, ry = dq.popleft()
            if dist[rx][ry] >= mind: continue
            for dx, dy in ((-1, 0), (0, -1), (0, 1), (1, 0)):
                nx, ny = rx+dx, ry+dy
                if 0 <= nx < n and 0 <= ny < n and dist[nx][ny] == -1:
                    if board[nx][ny] <= size:
                        dist[nx][ny] = dist[rx][ry]+1
                        if 0 < board[nx][ny] < size:
                            can.append((nx, ny))
                            mind = dist[nx][ny]
                        else:dq.append((nx, ny))
        if can: return min(can), mind
        else: return None
    while sh := getfish(x, y, size):
        (x, y), d = sh
        board[x][y] = 0
        time += d
        eat += 1
        if eat == size:
            size += 1
            eat = 0
    print(time)
    return
if __name__ == '__main__':
    main()