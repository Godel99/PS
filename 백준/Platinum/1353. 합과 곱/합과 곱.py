import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    s, p = map(int, input().split())
    if s == p: print(1); return
    n, d = 2, 0
    while True:
        m = pow(s/n, n)
        if m >= p: print(n); return
        if m < d: print(-1); return
        d = m
        n += 1
if __name__ == '__main__':
    main()