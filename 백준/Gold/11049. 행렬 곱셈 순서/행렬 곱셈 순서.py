import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    mat = [*map(int, input().split())] 
    for _ in range(1, n):
        _, c = map(int, input().split())
        mat.append(c)
    dp = [[0]*n for _ in range(n)]
    for l in range(1, n):
        for i in range(n-l):
            j = i+l
            dp[i][j] = 2_147_483_647
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(mat[i]*mat[k+1]*mat[j+1]))
    print(dp[0][-1])
    return
if __name__ == "__main__":
    main()