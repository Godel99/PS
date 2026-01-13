import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def rotate(key):
    n = len(key)
    nk = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            nk[j][n-1-i] = key[i][j]
    return nk

def isopen(n, board):
    for i in range(n, 2*n):
        for j in range(n, 2*n):
            if board[i][j] != 1: return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    board = [[0] * n*3 for _ in range(n*3)]
    for i in range(n):
        for j in range(n):
            board[i+n][j+n] = lock[i][j]
    cur = key
    for r in range(4):
        for x in range(2*n):
            for y in range(2*n):
                for i in range(m):
                    for j in range(m):
                        board[x+i][y+j] += cur[i][j]
                if isopen(n, board): return True
                for i in range(m):
                    for j in range(m):
                        board[x+i][y+j] -= cur[i][j]
        cur = rotate(cur)
    return False
def main():
    print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
if __name__ == '__main__':
    main()