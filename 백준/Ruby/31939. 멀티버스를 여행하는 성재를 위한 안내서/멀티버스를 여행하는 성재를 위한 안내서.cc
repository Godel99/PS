#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int G = 3;
const int IMG = 911660635; // MOD에 대한 sqrt(-1)

// 모듈러 거듭제곱
ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 모듈러 역원
ll inv(ll n) {
    return power(n, MOD - 2);
}

// NTT 구현 클래스
struct FastNTT {
    void ntt(vector<int>& a, bool invert) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            ll wlen = power(G, (MOD - 1) / len);
            if (invert) wlen = inv(wlen);
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
        if (invert) {
            ll n_inv = inv(n);
            for (int& x : a) x = (int)(1LL * x * n_inv % MOD);
        }
    }

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
} ntt;

// 다항식 크기 비교를 위한 구조체 (Priority Queue용)
struct Poly {
    vector<int> p;
    bool operator>(const Poly& other) const {
        return p.size() > other.p.size();
    }
};

// 다항식 뭉치를 하나로 합치는 함수 (분할 정복 최적화)
vector<int> merge_polys(priority_queue<Poly, vector<Poly>, greater<Poly>>& pq) {
    while (pq.size() > 1) {
        vector<int> a = pq.top().p; pq.pop();
        vector<int> b = pq.top().p; pq.pop();
        pq.push({ntt.multiply(a, b)});
    }
    return pq.top().p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll R;
    if (!(cin >> N >> R)) return 0;

    priority_queue<Poly, vector<Poly>, greater<Poly>> pq1, pq2;

    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        x = (x % MOD + MOD) % MOD;
        y = (y % MOD + MOD) % MOD;

        // Modular I를 이용한 복소수 근 설정
        // P1: (z - (x + iy)), P2: (z - (x - iy))
        int root1 = (int)((x + y * IMG) % MOD);
        int root2 = (int)((x - (y * IMG % MOD) + MOD) % MOD);

        pq1.push({{(int)((MOD - root1) % MOD), 1}});
        pq2.push({{(int)((MOD - root2) % MOD), 1}});
    }

    // 각각의 다항식 곱 전개
    vector<int> ans1 = merge_polys(pq1);
    vector<int> ans2 = merge_polys(pq2);

    ll total_expected_value = 0;
    ll R2 = (R % MOD) * (R % MOD) % MOD;
    ll current_R2k = 1;

    for (int k = 0; k <= N; k++) {
        // |c_k|^2 = c_k * conj(c_k) ≡ ans1[k] * ans2[k] (mod MOD)
        ll mag_sq = (1LL * ans1[k] * ans2[k]) % MOD;
        ll term = (mag_sq * current_R2k) % MOD;
        term = (term * inv(k + 1)) % MOD;

        total_expected_value = (total_expected_value + term) % MOD;
        current_R2k = (current_R2k * R2) % MOD;
    }

    cout << total_expected_value << endl;

    return 0;
}