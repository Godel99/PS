#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const long long PRIM_ROOT = 3;

long long power(long long a, long long b) {
    a %= MOD; if (a < 0) a += MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void ntt(vector<long long>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long w = power(PRIM_ROOT, (MOD - 1) / len);
        if (inv) w = power(w, MOD - 2);
        for (int i = 0; i < n; i += len) {
            long long wn = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j], v = a[i + j + len / 2] * wn % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                wn = wn * w % MOD;
            }
        }
    }
    if (inv) {
        long long ni = power(n, MOD - 2);
        for (auto& x : a) x = x * ni % MOD;
    }
}

// Complex polynomial: (real part, imaginary part)
using CPoly = pair<vector<long long>, vector<long long>>;

// Optimized complex poly multiply: 4 forward NTTs + 2 inverse NTTs (instead of 12)
CPoly cpoly_mul(CPoly A, CPoly B) {
    int sa = A.first.size(), sb = B.first.size();
    int sz = sa + sb - 1;
    int n = 1;
    while (n < sz) n <<= 1;

    A.first.resize(n); A.second.resize(n);
    B.first.resize(n); B.second.resize(n);

    ntt(A.first, false);
    ntt(A.second, false);
    ntt(B.first, false);
    ntt(B.second, false);

    vector<long long> R(n), I(n);
    for (int i = 0; i < n; i++) {
        long long ar = A.first[i], ai = A.second[i];
        long long br = B.first[i], bi = B.second[i];
        R[i] = (ar * br % MOD - ai * bi % MOD + MOD) % MOD;
        I[i] = (ar * bi % MOD + ai * br % MOD) % MOD;
    }

    ntt(R, true);
    ntt(I, true);
    R.resize(sz);
    I.resize(sz);
    return {move(R), move(I)};
}

vector<CPoly> leaves;

CPoly build(int l, int r) {
    if (r - l == 1) return leaves[l];
    int mid = (l + r) / 2;
    return cpoly_mul(build(l, mid), build(mid, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; long long R;
    cin >> N >> R;

    leaves.resize(N);
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        x %= MOD; if (x < 0) x += MOD;
        y %= MOD; if (y < 0) y += MOD;
        long long nx = (MOD - x) % MOD;
        long long ny = (MOD - y) % MOD;
        leaves[i] = {{nx, 1}, {ny, 0}};
    }

    auto [PR, PI] = build(0, N);

    // Precompute modular inverses 1..N+1
    vector<long long> inv_arr(N + 2);
    inv_arr[1] = 1;
    for (int i = 2; i <= N + 1; i++)
        inv_arr[i] = (MOD - MOD / i) * inv_arr[MOD % i] % MOD;

    R %= MOD;
    long long R2 = R * R % MOD;
    long long Rpow = 1;
    long long ans = 0;

    for (int k = 0; k <= N; k++) {
        long long re = PR[k], im = PI[k];
        long long a2 = (re * re % MOD + im * im % MOD) % MOD;
        ans = (ans + a2 * Rpow % MOD * inv_arr[k + 1]) % MOD;
        Rpow = Rpow * R2 % MOD;
    }

    cout << ans << "\n";
    return 0;
}