import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    n, m = map(int, input().split())
    dx, dy = (1, -1, 0, 0), (0, 0, 1, -1)
    board = []
    cheese = []
    for i in range(n):
        row = list(map(int, input().split()))
        for j in range(m):
            if row[j]: cheese.append((i, j))
        board.append(row)
    dq = deque([(0, 0)])
    board[0][0] = -1
    while dq:
        x, y = dq.popleft()
        for dir in range(4):
            nx, ny = x+dx[dir], y+dy[dir]
            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                board[nx][ny] = -1
                dq.append((nx, ny))
    time = 0
    while cheese:
        time += 1
        keep_cheese = []
        melt_cheese = deque()
        for x, y in cheese:
            cnt = 0
            for dir in range(4):
                if board[x+dx[dir]][y+dy[dir]] == -1: cnt += 1
            if cnt > 1: melt_cheese.append((x, y))
            else: keep_cheese.append((x, y))
        for x, y in melt_cheese: board[x][y] = -1
        while melt_cheese:
            x, y = melt_cheese.popleft()
            for dir in range(4):
                nx, ny = x+dx[dir], y+dy[dir]
                if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                    board[nx][ny] = -1
                    melt_cheese.append((nx, ny))
        cheese = keep_cheese
    print(time)
    return  
if __name__ == '__main__':
    main()