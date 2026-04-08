import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import log
E = 0.57721566490153286
N = 10_000

def main():
    dp = [0]*(N+1)
    for i in range(1, N+1): dp[i] = dp[i-1]+1/i
    t = int(input())
    for i in range(1, t+1):
        n = int(input())
        if n <= N: ans = dp[n]
        else:
            n2 = n * n
            n4 = n2 * n2
            ans = log(n)+E+1/(2*n)-1/(12*n2)+1/(120*n4)
        print(f'Case #{i}: {ans:.12f}')
    return
if __name__ == "__main__":
    main()