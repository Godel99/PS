import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    if board[0][2] == 1: print(0); return
    dp = [[[0]*3 for _ in range(n)] for _ in range(n)]
    dp[0][1][0] = 1
    for r in range(n):
        for c in range(2, n):
            if board[r][c] == 1: continue 
            if c > 0: dp[r][c][0] += dp[r][c-1][0] + dp[r][c-1][2]
            if r > 0: dp[r][c][1] += dp[r-1][c][1] + dp[r-1][c][2]
            if r > 0 and c > 0 and board[r-1][c] == 0 and board[r][c-1] == 0: dp[r][c][2] += sum(dp[r-1][c-1])
    print(sum(dp[n-1][n-1]))
if __name__ == '__main__':
    main()