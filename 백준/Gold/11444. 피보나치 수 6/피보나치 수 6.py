import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def mul(a, b):
        c = [[0]*2 for _ in range(2)]
        for i in range(2):
            for k in range(2):
                for j in range(2):
                    c[i][j] = (c[i][j]+a[i][k]*b[k][j])%MOD
        return c

def main():
    n = int(input())
    if n == 0: print(0); return
    base = [[1, 1], [1, 0]]
    ans = [[1, 0], [0, 1]]
    while n:
        if n&1: ans = mul(ans, base)
        base = mul(base, base)
        n >>= 1
    print(ans[0][1])
    return  
if __name__ == '__main__':
    main()