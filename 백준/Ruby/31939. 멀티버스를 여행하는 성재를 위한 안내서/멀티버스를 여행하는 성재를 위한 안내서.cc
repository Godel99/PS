#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

// 모듈러 거듭제곱
ll pw(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// 모듈러 역원
ll inv(ll a) {
    return pw(a, MOD - 2);
}

// NTT 클래스 구현
struct NTT {
    void ntt(vector<int>& a, bool invert) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            ll wlen = pw(3, (MOD - 1) / len);
            if (invert) wlen = inv(wlen);
            for (int i = 0; i < n; i += len) {
                ll w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                    a[i + j] = (u + v) % MOD;
                    a[i + j + len / 2] = (u - v + MOD) % MOD;
                    w = w * wlen % MOD;
                }
            }
        }
        if (invert) {
            ll n_inv = inv(n);
            for (int& x : a) x = (int)(1LL * x * n_inv % MOD);
        }
    }

    vector<int> conv(const vector<int>& a, const vector<int>& b) {
        vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < (int)(a.size() + b.size())) n <<= 1;
        fa.resize(n); fb.resize(n);
        ntt(fa, false); ntt(fb, false);
        for (int i = 0; i < n; i++) fa[i] = (int)(1LL * fa[i] * fb[i] % MOD);
        ntt(fa, true);
        return fa;
    }
} ntt_solver;

// 복소 다항식 구조체 (사용자 제공 로직 기반)
struct CPoly {
    vector<int> rea, ima;
    CPoly() {}
    CPoly(int n) {
        rea.assign(n, 0);
        ima.assign(n, 0);
    }
    size_t size() const { return rea.size(); }

    CPoly operator*(const CPoly &o) const {
        int final_sz = (int)(size() + o.size() - 1);
        auto S1 = ntt_solver.conv(rea, o.rea);
        auto S2 = ntt_solver.conv(ima, o.ima);
        
        vector<int> A(size()), B(o.size());
        for (int i = 0; i < (int)size(); i++) A[i] = (rea[i] + ima[i]) % MOD;
        for (int i = 0; i < (int)o.size(); i++) B[i] = (o.rea[i] + o.ima[i]) % MOD;
        
        auto S3 = ntt_solver.conv(A, B);
        
        CPoly C(final_sz);
        for (int i = 0; i < final_sz; i++) {
            C.rea[i] = (1LL * S1[i] - S2[i] + MOD) % MOD;
            C.ima[i] = (1LL * S3[i] - S1[i] - S2[i] + 2LL * MOD) % MOD;
        }
        return C;
    }
};

CPoly make(int a, int b) {
    CPoly P(2);
    P.rea[0] = (MOD - a % MOD) % MOD;
    P.ima[0] = (MOD - b % MOD) % MOD;
    P.rea[1] = 1;
    P.ima[1] = 0;
    return P;
}

// 분할 정복을 통한 다항식 곱셈
CPoly solve_poly(int l, int r, const vector<pair<int, int>>& points) {
    if (l == r) return make(points[l].first, points[l].second);
    int mid = (l + r) / 2;
    return solve_poly(l, mid, points) * solve_poly(mid + 1, r, points);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll R;
    if (!(cin >> N >> R)) return 0;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { (x % MOD + MOD) % MOD, (y % MOD + MOD) % MOD };
    }

    // 모든 (z - Z_j) 곱하기
    CPoly Q = solve_poly(0, N - 1, points);

    ll ans = 0;
    ll R2 = (R % MOD) * (R % MOD) % MOD;
    ll current_R2k = 1;

    // 기댓값 E = sum |c_k|^2 * R^(2k) / (k + 1)
    for (int k = 0; k <= N; k++) {
        ll mag_sq = (1LL * Q.rea[k] * Q.rea[k] + 1LL * Q.ima[k] * Q.ima[k]) % MOD;
        ll term = mag_sq * current_R2k % MOD;
        term = term * inv(k + 1) % MOD;
        
        ans = (ans + term) % MOD;
        current_R2k = current_R2k * R2 % MOD;
    }

    cout << ans << endl;

    return 0;
}