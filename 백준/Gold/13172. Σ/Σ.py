import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    m = int(input())
    ans = 0
    for _ in range(m):
        n, s = map(int, input().split())
        ans = (ans+s*pow(n, MOD-2, MOD))%MOD
    print(ans)
    return
if __name__ == '__main__':
    main()