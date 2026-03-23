import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, k = map(int, input().split())
    def f(n, k):
        if n >= k: return n-k, 1
        if k == 1: return 1, 1
        if k&1:
            a, b = f(n, k-1)
            c, d = f(n, k+1)
            if a == c: return-~a, b+d
            elif a < c: return-~a, b
            else: return -~c, d
        else:
            a, b = f(n, k>>1)
            if k-n == a+1: return k-n, -~b
            elif k-n < a+1: return k-n, 1
            else: return -~a, b
    print(*f(n, k))
    return
if __name__ == '__main__':
    main()