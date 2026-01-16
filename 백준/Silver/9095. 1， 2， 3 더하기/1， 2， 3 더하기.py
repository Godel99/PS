import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()
    
def main():
    t = int(input())
    dp = [0] * 11
    for _ in range(t):
        n = int(input())
        dp[1] = 1
        dp[2] = 2
        dp[3] = 4
        for i in range(4, n+1):
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
        print(dp[n])
if __name__ == '__main__':

    main()
