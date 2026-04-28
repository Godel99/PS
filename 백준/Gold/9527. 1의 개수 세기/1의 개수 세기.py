import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    a, b = map(int, input().split())
    memo = {0: 0, 1: 1}
    def bitcnt(n):
        if n in memo: return memo[n]
        k = 0
        while 1 << (k+1) <= n: k += 1
        msb = 1<<k
        memo[n] = k*(1<<(k-1))+(n-msb+1)+bitcnt(n-msb)
        return memo[n]
    print(bitcnt(b) - bitcnt(a-1))
    return
if __name__ == "__main__":
    main()