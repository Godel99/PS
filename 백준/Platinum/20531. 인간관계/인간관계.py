import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    n, m = map(int, input().split())
    dp = [[0]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        dp[i][0] = dp[i][1] = 1
        for j in range(2, i+1):
            dp[i][j] = (dp[i-1][j]*j+dp[i-1][j-1])%MOD
            dp[i][0] = (dp[i][0]+dp[i][j])%MOD
    com = n
    def f(x):
        if par[x] < 0: return x
        par[x] = f(par[x])
        return par[x]
    def u(x, y):
        nonlocal com
        x = f(x); y = f(y)
        if x == y: return
        com -= 1
        if par[x] > par[y]: x, y = y, x
        par[x] += par[y]
        par[y] = x
    par = [-1]*(n+1)
    for _ in range(m):
        x, y = map(int, input().split())
        u(x, y)
        print(dp[com][0])
if __name__ == '__main__':
    main()