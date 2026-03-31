import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, b = map(int, input().split())
    m = [list(map(int, input().split())) for _ in range(n)]
    def mul(u, v, n):
        ret = [[0]*n for _ in range(n)]
        for i in range(n):
            for k in range(n):
                for j in range(n):
                    ret[i][j] = (ret[i][j]+u[i][k]*v[k][j])%1000
        return ret
    def pw(m, b, n):
        if b == 1: 
            for i in range(n):
                for j in range(n):
                    m[i][j] %= 1000
            return m
        h = pw(m, b//2, n)
        if b&1: return mul(mul(h, h, n), m, n)
        else: return mul(h, h, n)
    for row in pw(m, b, n): print(' '.join(map(str, row)))
    return
if __name__ == '__main__':
    main()