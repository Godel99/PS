import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, k = map(int, input().split())
    def f(n, k):
        if n >= k: return n-k, *range(n, k-1, -1)
        if k == 1: return 1, 0, 1
        if k&1:
            a, *b = f(n, k-1)
            c, *d = f(n, k+1)
            return [[c+1, *d, k], [a+1, *b, k]][a<c]
        else:
            a, *b = f(n, k//2)
            return [[a+1, *b, k], [k-n, *range(n, k+1)]][k-n < a+1]
    print(*f(n, k))
if __name__ == '__main__':
    main()