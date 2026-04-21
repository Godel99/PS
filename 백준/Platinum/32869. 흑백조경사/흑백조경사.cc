#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> c(n + 1);
    int W = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == 0) W++; else B++;
    }
    int D = W - B;
    auto val = [&](int i) -> int { return c[i] == 0 ? 1 : -1; };

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // 1번 기준 DFS: in/out time, 서브트리 합 f[] 계산
    vector<int> in_t(n+1), out_t(n+1), par(n+1,0), f(n+1,0);
    vector<vector<int>> ch(n+1);
    int timer = 0;
    {
        vector<bool> vis(n+1, false);
        vector<int> it(n+1, 0), stk;
        stk.reserve(n); stk.push_back(1); vis[1] = true;
        while (!stk.empty()) {
            int v = stk.back();
            if (it[v] == 0) { in_t[v] = ++timer; f[v] = val(v); }
            bool pushed = false;
            while (it[v] < (int)adj[v].size()) {
                int u = adj[v][it[v]++];
                if (!vis[u]) {
                    vis[u] = true; par[u] = v;
                    ch[v].push_back(u); stk.push_back(u);
                    pushed = true; break;
                }
            }
            if (!pushed) {
                out_t[v] = timer;
                if (par[v]) f[par[v]] += f[v];
                stk.pop_back();
            }
        }
    }

    // 차이 배열로 나쁜 루트 마킹
    vector<int> diff(n + 2, 0);
    auto mark = [&](int l, int r) {
        if (l > r) return;
        diff[l]++; diff[r+1]--;
    };

    for (int v = 1; v <= n; v++) {
        int sv = val(v);

        // 루트 조건: r = v
        if ((D - sv) * sv < 0)
            mark(in_t[v], in_t[v]);

        if (deg[v] >= 2) {
            // 정적 조건: r ∉ subtree(v)
            int sd = f[v] - sv;
            if (sd * sv < 0) {
                mark(1, in_t[v] - 1);
                mark(out_t[v] + 1, n);
            }
            // 자식 조건: r ∈ subtree(u)
            for (int u : ch[v]) {
                int dn = D - f[u] - sv;
                if (dn * sv < 0)
                    mark(in_t[u], out_t[u]);
            }
        }
    }

    // 전위합 계산
    for (int i = 1; i <= n; i++) diff[i] += diff[i-1];

    // 유효 루트 수집
    vector<int> ans;
    for (int v = 1; v <= n; v++)
        if (diff[in_t[v]] == 0)
            ans.push_back(v);

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    if (!ans.empty()) cout << "\n";

    return 0;
}