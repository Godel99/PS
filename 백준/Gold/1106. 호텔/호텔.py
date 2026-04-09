import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import inf

def main():
    c, n = map(int, input().split())
    nc = c+100
    dp = [inf]*(nc+1)
    dp[0] = 0
    for _ in range(n):
        cst, peo = map(int, input().split())
        for i in range(peo, nc+1):
            if dp[i-peo] != inf:
                dp[i] = min(dp[i], dp[i-peo]+cst)
    print(min(dp[c:]))
    return
if __name__ == "__main__":
    main()