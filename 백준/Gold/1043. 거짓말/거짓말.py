import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, m = map(int, input().split())
    par = [-1]*(n+1)
    def f(x):
        if par[x] < 0: return x
        par[x] = f(par[x])
        return par[x]
    def u(x, y):
        x, y = f(x), f(y)
        if x == y: return
        if par[x] > par[y]: x, y = y, x
        par[x] += par[y]
        par[y] = x
    k, *a = map(int, input().split())
    if k == 0: print(m); return
    for aa in a: u(0, aa)
    party = [list(map(int, input().split())) for _ in range(m)]
    for p in party:
        l, *b = p
        if l > 1:
            for i in range(1, l): u(b[i-1], b[i])
    for p in party:
        l, *b = p
        for bb in b:
            if f(bb) == f(0): m -= 1; break
    print(m)
    return
if __name__ == '__main__':
    main()