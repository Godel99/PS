import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    a = [0]+[*map(int, input().split())]
    dp = [[False]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1): dp[i][i] = True
    for i in range(1, n):
        if a[i] == a[i+1]: dp[i][i+1] = True
    for d in range(2, n):
        for s in range(1, n-d+1):
            e = s+d
            if a[s] == a[e] and dp[s+1][e-1]: dp[s][e] = True
    m = int(input())
    ans = []
    for _ in range(m):
        s, e = map(int, input().split())
        ans.append('1' if dp[s][e] else '0')
    print('\n'.join(ans))
    return
if __name__ == "__main__":
    main()