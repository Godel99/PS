#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int G = 3;
const int IMG = 911660635; // sqrt(-1) mod MOD

// 모듈러 거듭제곱
ll power(ll a, ll b) {
    ll res = 1; a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 표준 NTT 구현 (비트 반전 포함)
void ntt(vector<int>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = power(G, (MOD - 1) / len);
        if (inv) wlen = power(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                a[i + j] = (u + v >= MOD) ? (u + v - MOD) : (u + v);
                a[i + j + len / 2] = (u - v < 0) ? (u - v + MOD) : (u - v);
                w = w * wlen % MOD;
            }
        }
    }
    if (inv) {
        ll n_inv = power(n, MOD - 2);
        for (int& x : a) x = (int)(1LL * x * n_inv % MOD);
    }
}

// 다항식 곱셈 함수
vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1, target = a.size() + b.size() - 1;
    while (n < target) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = (int)(1LL * a[i] * b[i] % MOD);
    ntt(a, true);
    a.resize(target);
    return a;
}

// 분할 정복을 통한 다항식 전개
vector<int> solve(int l, int r, const vector<int>& roots) {
    if (l == r) {
        return { (MOD - roots[l]) % MOD, 1 };
    }
    int mid = (l + r) >> 1;
    return multiply(solve(l, mid, roots), solve(mid + 1, r, roots));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; ll R;
    if (!(cin >> N >> R)) return 0;

    vector<int> r1(N), r2(N);
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        x = (x % MOD + MOD) % MOD;
        y = (y % MOD + MOD) % MOD;
        // z - (x + iy)와 z - (x - iy)를 각각 구성
        r1[i] = (x + y * IMG) % MOD;
        r2[i] = (x - (y * IMG % MOD) + MOD) % MOD;
    }

    // 두 개의 독립적인 다항식 전개
    vector<int> Q1 = solve(0, N - 1, r1);
    vector<int> Q2 = solve(0, N - 1, r2);

    // k+1의 역원을 선형 시간에 사전 계산
    vector<int> inv_table(N + 2);
    inv_table[1] = 1;
    for (int i = 2; i <= N + 1; i++)
        inv_table[i] = (int)(1LL * (MOD - MOD / i) * inv_table[MOD % i] % MOD);

    ll ans = 0;
    ll R2 = (R % MOD) * (R % MOD) % MOD;
    ll curR = 1;

    for (int k = 0; k <= N; k++) {
        // |c_k|^2 = (a_k + I*b_k)(a_k - I*b_k) = a_k^2 + b_k^2
        ll mag_sq = (1LL * Q1[k] * Q2[k]) % MOD;
        ll term = (mag_sq * curR) % MOD;
        term = (term * inv_table[k + 1]) % MOD;
        ans = (ans + term) % MOD;
        curR = (curR * R2) % MOD;
    }

    cout << ans << endl;

    return 0;
}