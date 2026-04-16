import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n, k = map(int, input().split())
    b = [*map(int, input().split())]
    a = [b[0]]
    for i in range(1, n):
        if b[i] != b[i-1]: a.append(b[i])
    m = len(a)
    dp = [[0]*(m) for _ in range(m)]
    for d in range(1, m):
        for l in range(m-d):
            r, mind = l+d, d
            for mid in range(l, r):
                mind = min(mind, dp[l][mid]+dp[mid+1][r]+(a[l] != a[mid+1]))
            dp[l][r] = mind
    print(dp[0][-1])
    return
if __name__ == "__main__":
    main()