import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    MOD = 998244353
    n, m, k = map(int, input().split())
    deg = [0] * (n + 1)
    for _ in range(m):
        _, y = map(int, input().split())
        deg[y] += 1

    vcnt = [0] * (m + 1)
    maxd = 0
    for i in range(2, n + 1):
        if deg[i]:
            vcnt[deg[i]] += 1
            if deg[i] > maxd:
                maxd = deg[i]

    if maxd == 0:
        print(0)
        return

    # ── 1. 역팩토리얼 precompute ──────────────────────────────────────
    size = maxd + 3
    fact = [1] * size
    for i in range(1, size):
        fact[i] = fact[i-1] * i % MOD
    inv_fact = [1] * size
    inv_fact[size-1] = pow(fact[size-1], MOD-2, MOD)
    for i in range(size-2, -1, -1):
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD

    # ── 2. fall, inv_fall, inv_kj precompute ─────────────────────────
    # Lagrange 보간은 k > d+1 (즉 k >= d+2) 일 때만 사용되므로
    # 접근하는 최대 인덱스 = d+1 <= k-1
    # → k-1까지만 계산하면 충분하고, 그 범위에서 fall 원소는 모두 양수
    safe_end = min(k - 1, maxd + 1)  # 실제 필요한 최대 인덱스
    fall_size = safe_end + 1

    fall = [0] * fall_size
    fall[0] = k % MOD
    for i in range(1, fall_size):
        fall[i] = fall[i-1] * ((k - i) % MOD) % MOD

    inv_fall = [0] * fall_size
    inv_fall[-1] = pow(fall[-1], MOD-2, MOD)
    for i in range(fall_size-2, -1, -1):
        inv_fall[i] = inv_fall[i+1] * ((k - i - 1) % MOD) % MOD

    # inv_kj[i] = 1/(k-i)
    inv_kj = [0] * fall_size
    inv_kj[0] = inv_fall[0]
    for i in range(1, fall_size):
        inv_kj[i] = fall[i-1] * inv_fall[i] % MOD

    # ── 3. invk^d precompute ─────────────────────────────────────────
    invk = pow(k % MOD, MOD-2, MOD)
    invk_pow = [1] * (maxd + 1)
    for i in range(1, maxd + 1):
        invk_pow[i] = invk_pow[i-1] * invk % MOD

    # ── Lagrange 보간으로 sum_{i=1}^{k} i^d 계산 ─────────────────────
    def Sd(d):
        pts = d + 1 if k > d + 1 else k
        y = [0] * (pts + 1)
        for i in range(1, pts + 1):
            y[i] = (y[i-1] + pow(i, d, MOD)) % MOD
        if k <= d + 1:
            return y[k]

        P = fall[d + 1]
        ret = 0
        for i in range(d + 2):
            num = P * inv_kj[i] % MOD
            den = inv_fact[i] * inv_fact[d + 1 - i] % MOD
            if (d + 1 - i) % 2:
                den = MOD - den
            ret = (ret + y[i] * num % MOD * den) % MOD
        return ret

    ans = 0
    for d in range(1, maxd + 1):
        if vcnt[d] == 0:
            continue
        evmd = Sd(d) * invk_pow[d] % MOD
        ans = (ans + vcnt[d] * evmd) % MOD

    print(ans)

if __name__ == "__main__":
    main()