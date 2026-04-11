import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, k = map(int, input().split())
    def f(n, k):
        if n >= k: return n-k
        if k == 1: return abs(~-n)
        if k&1: return -~min(f(n, ~-k), f(n, -~k))
        else: return min(k-n, f(n, k>>1))
    print(f(n, k))
    return
if __name__ == '__main__':
    main()