import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, k = map(int, input().split())
    dp = [0]*(k+1)
    for _ in range(n):
        w, v = map(int, input().split())
        if w > k: continue
        for i in range(k, w-1, -1): dp[i] = max(dp[i], dp[i-w]+v)
    print(dp[k])
if __name__ == '__main__':
    main()