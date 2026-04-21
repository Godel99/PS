#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 150001;
const int LOG   = 18;    // 2^17 = 131072 < 150000 < 2^18

int  d[17][MAXN + 2];    // 차이 배열
int  ans[MAXN];          // D[i]
int  sparse[LOG][MAXN];  // Sparse Table
int  qx[MAXN], qy[MAXN], qz[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int M = m;
    for (int i = 0; i < M; i++) {
        cin >> qx[i] >> qy[i] >> qz[i];
        d[qz[i]][qx[i]]++;
        d[qz[i]][qy[i] + 1]--;
    }

    // ── 1단계: D[i] 계산 (유저 방식: z=1~16 직접 LCM) ────────────
    fill(ans, ans + n, 1);
    for (int z = 1; z <= 16; z++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += d[z][i];
            if (cnt) ans[i - 1] = lcm(ans[i - 1], z);
        }
    }

    // ── 2단계: Sparse Table 구성 (O(N log N)) ─────────────────────
    for (int i = 0; i < n; i++) sparse[0][i] = ans[i];

    for (int j = 1; j < LOG; j++) {
        int half = 1 << (j - 1);
        for (int i = 0; i + half < n; i++)
            sparse[j][i] = __gcd(sparse[j-1][i], sparse[j-1][i + half]);
        // 범위 초과 구간은 이전 레벨 값 복사 (쿼리 분기 제거용)
        for (int i = max(0, n - half); i < n; i++)
            sparse[j][i] = sparse[j-1][i];
    }

    // ── 3단계: 조건 검증 (Sparse Table O(1) 쿼리) ─────────────────
    for (int i = 0; i < M; i++) {
        int l = qx[i] - 1, r = qy[i] - 1;
        int k = __lg(r - l + 1);
        int res = __gcd(sparse[k][l], sparse[k][r - (1 << k) + 1]);
        if (res != qz[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // ── 4단계: 출력 ───────────────────────────────────────────────
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];

    return 0;
}