import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        score = [[0]+list(map(int, input().split())) for _ in range(2)]
        dp = [[0]*(n+1) for _ in range(2)]
        dp[0][1], dp[1][1] = score[0][1], score[1][1]
        for i in range(2, n+1):
            dp[0][i] = max(dp[1][i-1], dp[1][i-2])+score[0][i]
            dp[1][i] = max(dp[0][i-1], dp[0][i-2])+score[1][i]
        print(max(dp[0][-1], dp[1][-1]))
if __name__ == '__main__':
    main()