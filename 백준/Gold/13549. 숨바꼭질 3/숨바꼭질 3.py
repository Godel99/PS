import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, k = map(int, input().split())
    def f(n, k):
        if n >= k: return n-k
        if k == 1: return abs(n-1)
        if k&1: return -~min(f(n, k-1), f(n, k+1))
        else: return min(k-n, f(n, k//2))
    print(f(n, k))
if __name__ == '__main__':
    main()