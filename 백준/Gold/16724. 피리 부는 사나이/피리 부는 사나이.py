import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n, m = map(int, input().split())
    board = [input() for _ in range(n)]
    vis = [[0]*m for _ in range(n)]
    ans = idx = 0
    move = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
    for i in range(n):
        for j in range(m):
            if vis[i][j]: continue
            idx += 1
            x, y = i, j
            while not vis[x][y]:
                vis[x][y] = idx
                dx, dy = move[board[x][y]]
                x, y = x+dx, y+dy
            if vis[x][y] == idx: ans += 1
    print(ans)
    return
if __name__ == "__main__":
    main()