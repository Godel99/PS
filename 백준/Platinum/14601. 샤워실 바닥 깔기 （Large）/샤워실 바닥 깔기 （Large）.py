import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def rf(sx, sy, size, x, y):
    global cnt
    if size == 2:
        if sx != x or sy != y: board[sy][sx] = cnt
        if sx+1 != x or sy != y: board[sy][sx+1] = cnt
        if sx != x or sy+1 != y: board[sy+1][sx] = cnt
        if sx+1 != x or sy+1 != y: board[sy+1][sx+1] = cnt
        cnt += 1
        return
    size >>= 1
    hx = sx+size; hy = sy+size
    board[hy-1][hx-1] = board[hy-1][hx] = board[hy][hx-1] = board[hy][hx] = cnt
    cnt += 1
    if x < hx and y < hy: rf(sx, sy, size, x, y)
    else: rf(sx, sy, size, hx-1, hy-1)
    if x >= hx and y < hy: rf(hx, sy, size, x, y)
    else: rf(hx, sy, size, hx, hy-1)
    if x < hx and y >= hy: rf(sx, hy, size, x, y)
    else: rf(sx, hy, size, hx-1, hy)
    if x >= hx and y >= hy: rf(hx, hy, size, x, y)
    else: rf(hx, hy, size, hx, hy)

def main():
    k = int(input())
    x, y = map(int, input().split())
    n = 1<<k
    global board, cnt
    board = [[0] * 130 for _ in range(130)]
    cnt = 1
    rf(1, 1, n, x, y)
    board[y][x] = -1
    for i in range(n, 0, -1):
        for j in range(1, n+1): print(board[i][j], end=' ')
        print()
    return 0
if __name__ == '__main__':
    sys.exit(main())