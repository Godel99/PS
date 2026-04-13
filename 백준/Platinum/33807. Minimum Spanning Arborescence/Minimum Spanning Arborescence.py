import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    MOD = 998244353
    n, m, k = map(int, input().split())
    deg = [0]*(n+1)
    for _ in range(m):
        _, y = map(int, input().split())
        deg[y] += 1
    vcnt = [0]*(m+1)
    for i in range(2, n+1):
        if deg[i]: vcnt[deg[i]] += 1
    prime = []
    spf = [0]*(k+1)
    for i in range(2, k+1):
        if spf[i] == 0:
            spf[i] = i
            prime.append(i)
        for p in prime:
            if p > spf[i] or i*p > k: break
            spf[i*p] = p
    inv = pow(k, MOD-2, MOD)
    ans = 0
    v = [0]*(k+1); v[1] = 1
    for d in range(1, m+1):
        if vcnt[d] == 0: continue
        sumv = 1
        for i in range(2, k+1):
            if spf[i] == i: v[i] = pow(i, d, MOD)
            else: v[i] = (v[spf[i]]*v[i//spf[i]])%MOD
            sumv = (sumv+v[i])%MOD
        evmd = (sumv*pow(inv, d, MOD))%MOD
        ans = (ans+(vcnt[d]*evmd)%MOD)%MOD
    print(ans)
    return
if __name__ == "__main__":
    main()