#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> e(n+1);
    vector<int> c(n+1, 0), isEven(n+1, 0), w(n+1, 0), b(n+1, 0), cnt(n+1, 0), ans;
    int tw = 0, tb = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(c[i]) tb++;
        else tw++;
    }
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int cur, int pre){
        isEven[cur] = 1;
        if(c[cur]) b[cur] = 1;
        else w[cur] = 1;
        for(int nxt : e[cur]){
            if(pre == nxt) continue;
            dfs(nxt, cur);
            b[cur] += b[nxt];
            w[cur] += w[nxt];
            isEven[cur] &= isEven[nxt];
            if(!isEven[nxt]) cnt[cur]++;
        }
        if(c[cur] && (w[cur] >= b[cur]) || !c[cur] && (b[cur] >= w[cur])) isEven[cur] = 0;
    };
    function<void(int, int)> sol = [&](int cur, int pre){
        if(!cnt[cur] && (c[cur] && (tw < tb) || !c[cur] && (tb < tw))) ans.push_back(cur);
        if(cnt[cur] >= 2) return;
        for(int nxt : e[cur]){
            if(nxt == pre) continue;
            if(cnt[cur] && isEven[nxt]) continue;
            if(c[cur] && (tw-w[nxt] >= tb-b[nxt]) || !c[cur] && (tb-b[nxt] >= tw-w[nxt])) continue;
            sol(nxt, cur);
        }
    };
    dfs(1, 1);
    sol(1, 1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << ' ';
    return 0;
}