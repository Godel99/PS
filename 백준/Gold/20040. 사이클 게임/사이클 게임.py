import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n, m = map(int, input().split())
    par = [-1]*n
    def find(x):
        if par[x] < 0: return x
        par[x] = find(par[x])
        return par[x]
    def unite(x, y):
        x, y = find(x), find(y)
        if x == y: return False
        if par[x] > par[y]: x, y = y, x
        par[x] += par[y]
        par[y] = x
        return True
    for i in range(1, m+1):
        s, e = map(int, input().split())
        if not unite(s, e): print(i); return
    print(0)
    return
if __name__ == "__main__":
    main()