import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    dp = [list(map(int, input().split())) for _ in range(n)]
    for i in range(n-2, -1, -1):
        for j in range(i+1): dp[i][j] += max(dp[i+1][j], dp[i+1][j+1])
    print(dp[0][0])
if __name__ == '__main__':
    main()