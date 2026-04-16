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
    dp = [[-1]*(m) for _ in range(m)]
    def df(l, r):
        if l >= r: return 0
        if dp[l][r] != -1: return dp[l][r]
        ret = float('inf')
        for i in range(l, r):
            ret = min(ret, df(l, i)+df(i+1, r)+(a[l] != a[i+1]))
        dp[l][r] = ret
        return ret
    print(df(0, m-1))
    return
if __name__ == "__main__":
    main()