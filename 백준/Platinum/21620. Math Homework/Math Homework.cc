#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 최대공약수 함수 (C++17부터는 std::gcd 사용 가능)
long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 입출력 최적화를 위한 구조체
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
} fast_io;

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> xs(M), ys(M), zs(M);
    for (int i = 0; i < M; ++i) {
        cin >> xs[i] >> ys[i] >> zs[i];
        xs[i]--; ys[i]--; // 0-based index 변환
    }

    vector<long long> D(N, 1);
    int primes[] = {2, 3, 5, 7, 11, 13};

    for (int p : primes) {
        int max_e = 0;
        int pk = p;
        while (pk <= 16) {
            max_e++;
            if (16 / p < pk) break; // 오버플로우 방지
            pk *= p;
        }

        vector<int> vp(M, 0);
        for (int i = 0; i < M; ++i) {
            int t = zs[i];
            while (t % p == 0) {
                vp[i]++;
                t /= p;
            }
        }

        vector<int> max_exp(N, 0);
        // 지수 e별로 차분 배열 적용
        for (int e = 1; e <= max_e; ++e) {
            vector<int> diff(N + 1, 0);
            for (int i = 0; i < M; ++i) {
                if (vp[i] >= e) {
                    diff[xs[i]]++;
                    diff[ys[i] + 1]--;
                }
            }
            int cur = 0;
            for (int i = 0; i < N; ++i) {
                cur += diff[i];
                if (cur > 0) max_exp[i] = e;
            }
        }

        // 전처리된 지수를 결과 배열 D에 반영
        for (int i = 0; i < N; ++i) {
            if (max_exp[i] > 0) {
                long long multiplier = 1;
                for (int e = 0; e < max_exp[i]; ++e) multiplier *= p;
                D[i] *= multiplier;
            }
        }
    }

    // Sparse Table 구성 (Sparse Table은 전역이나 큰 배열로 선언하는 게 좋음)
    int LOG = 32 - __builtin_clz(N); // log2(N) 계산
    vector<vector<long long>> table(LOG, vector<long long>(N));

    for (int i = 0; i < N; ++i) table[0][i] = D[i];

    for (int j = 1; j < LOG; ++j) {
        int shift = 1 << (j - 1);
        for (int i = 0; i + (1 << j) <= N; ++i) {
            table[j][i] = get_gcd(table[j - 1][i], table[j - 1][i + shift]);
        }
    }

    // 구간 GCD 쿼리 함수 (람다)
    auto range_gcd = [&](int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return get_gcd(table[k][l], table[k][r - (1 << k) + 1]);
    };

    // 모든 조건 검증
    for (int i = 0; i < M; ++i) {
        if (range_gcd(xs[i], ys[i]) != zs[i]) {
            cout << "Impossible" << "\n";
            return 0;
        }
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        cout << D[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}