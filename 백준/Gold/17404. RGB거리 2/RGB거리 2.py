import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import inf

def main():
    n = int(input())
    cost = [[*map(int, input().split())] for _ in range(n)]
    ans = []
    for c in range(3):
        dp = [[inf]*3 for _ in range(n)]
        dp[0][c] = cost[0][c]
        for i in range(1, n):
            dp[i][0] = min(dp[i-1][1], dp[i-1][2])+cost[i][0]
            dp[i][1] = min(dp[i-1][0], dp[i-1][2])+cost[i][1]
            dp[i][2] = min(dp[i-1][0], dp[i-1][1])+cost[i][2]
        ans.append(min(dp[-1][(c+1)%3], dp[-1][(c+2)%3]))
    print(min(ans))
    return
if __name__ == "__main__":
    main()