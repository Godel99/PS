#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

// 모듈러 거듭제곱
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 모듈러 역원
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// 수론적 변환 (Number Theoretic Transform)
void ntt(vector<long long>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(3, (MOD - 1) / len);
        if (invert) wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j];
                long long v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (w * wlen) % MOD;
            }
        }
    }
    if (invert) {
        long long n_inv = modInverse(n);
        for (long long& x : a) x = (x * n_inv) % MOD;
    }
}

// 두 다항식의 곱셈
vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    ntt(fa, false); ntt(fb, false);
    for (int i = 0; i < n; i++) fa[i] = (fa[i] * fb[i]) % MOD;
    ntt(fa, true);
    
    vector<long long> result(a.size() + b.size() - 1);
    for (int i = 0; i < result.size(); i++) result[i] = fa[i];
    return result;
}

// 분할 정복을 이용한 다항식 전개 P(z) = \prod (z - root[i])
vector<long long> solve_poly(int l, int r, const vector<long long>& roots) {
    if (l == r) {
        long long const_term = (MOD - roots[l] % MOD) % MOD;
        return {const_term, 1LL}; // (z - root)
    }
    int mid = l + (r - l) / 2;
    return multiply(solve_poly(l, mid, roots), solve_poly(mid + 1, r, roots));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    long long R;
    if (!(cin >> N >> R)) return 0;
    
    // 허수 단위 I 계산 (I^2 = -1 mod 998244353)
    long long I = power(3, (MOD - 1) / 4);
    
    vector<long long> roots1(N), roots2(N);
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        x = (x % MOD + MOD) % MOD;
        y = (y % MOD + MOD) % MOD;
        
        roots1[i] = (x + y * I) % MOD;
        roots2[i] = (x - (y * I % MOD) + MOD) % MOD;
    }
    
    // P1(z)와 P2(z) 다항식 계산
    vector<long long> P1 = solve_poly(0, N - 1, roots1);
    vector<long long> P2 = solve_poly(0, N - 1, roots2);
    
    long long expected_value = 0;
    long long R_sq = (R % MOD) * (R % MOD) % MOD;
    long long current_R2k = 1;
    
    // 기대값 계산 E[F] = \sum (|c_k|^2 * R^{2k}) / (k + 1)
    for (int k = 0; k <= N; k++) {
        long long term = (P1[k] * P2[k]) % MOD;
        term = (term * current_R2k) % MOD;
        term = (term * modInverse(k + 1)) % MOD;
        
        expected_value = (expected_value + term) % MOD;
        current_R2k = (current_R2k * R_sq) % MOD;
    }
    
    cout << expected_value << "\n";
    return 0;
}