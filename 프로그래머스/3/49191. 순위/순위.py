import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def solution(n, results):
    win = [[False] * n for _ in range(n)]
    for i, j in results:
        win[i-1][j-1] = True
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if win[i][k] and win[k][j]:
                    win[i][j] = True
    cnt = 0
    for i in range(n):
        w = 0; l = 0
        for j in range(n):
            w += win[i][j]
            l += win[j][i]
        if w + l == n - 1:
            cnt += 1
    return cnt

def main():
    print(solution(5,	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
if __name__ == '__main__':
    main()