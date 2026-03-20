import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    while nx := list(map(int, input().split())):
        n, x = nx
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        xx = pow(x, n-1, MOD)
        for i in range(n): x = (x+a[i]*b[i]%MOD)%MOD
        print(xx*x%MOD)
if __name__ == '__main__':
    main()