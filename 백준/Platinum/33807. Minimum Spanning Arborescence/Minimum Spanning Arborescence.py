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
    maxd = 0
    for i in range(2, n+1):
        if deg[i]: vcnt[deg[i]] += 1
        if deg[i] > maxd: maxd = deg[i]
    fact = [1]*(maxd+3)
    invf = [1]*(maxd+3)
    for i in range(1, maxd+3): fact[i] = (fact[i-1]*i)%MOD
    invf[maxd+2] = pow(fact[maxd+2], MOD-2, MOD)
    for i in range(maxd+1, -1, -1): invf[i] = (invf[i+1]*(i+1))
    def Sd(d):
        y = [0]*(d+2)
        for i in range(1, d+2): y[i] = (y[i-1]+pow(i, d, MOD))%MOD
        pref = [1]*(d+2)
        suff = [1]*(d+2)
        pref[0] = k
        for i in range(1, d+2): pref[i] = (pref[i-1]*(k-i))%MOD
        suff[d+1] = (k-d-1)
        for i in range(d, -1, -1): suff[i] = (suff[i+1]*(k-i))%MOD
        ret = 0
        for i in range(d+2):
            num = 1
            if i > 0: num = (num*pref[i-1])%MOD
            if i < d+1: num = (num*suff[i+1])%MOD
            den = (invf[i]*invf[d+1-i])%MOD
            if (d+1-i)%2: den = MOD-den
            ret = (ret+y[i]*num*den)%MOD
        return ret
    ans = 0
    for d in range(1, maxd+1):
        if vcnt[d] == 0: continue
        invk = pow(pow(k, d, MOD), MOD-2, MOD)
        evmd = (vcnt[d]*Sd(d)*invk)%MOD
        ans = (ans+evmd)%MOD
    print(ans)
    return
if __name__ == "__main__":
    main()