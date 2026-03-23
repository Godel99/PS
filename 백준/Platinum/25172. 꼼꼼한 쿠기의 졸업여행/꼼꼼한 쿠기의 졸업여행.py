import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    vis = [0]*(n+1)
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
    for _ in range(m):
        x, y = map(int, input().split())
        e[x].append(y)
        e[y].append(x)
    st = [int(input()) for _ in range(n)]
    ans = []
    for i in range(1, n+1):
        cur = st[-i]
        vis[cur] = 1
        for nxt in e[cur]:
            if vis[nxt]: u(cur, nxt)
        ans.append(par[f(cur)] == -i)
    while ans: print('CONNECT' if ans.pop() else 'DISCONNECT')
    print('DISCONNECT')
    return
if __name__ == '__main__':
    main()