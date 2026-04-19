#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> p(n+1), v(n+1), ans(n);
    vector<vector<int>> e(n+1);
    vector<set<int>> s(n+1);
    int root = -1;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] == -1) root = i;
        else e[p[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> v[i];
    function<void(int)> dfs = [&](int cur){
        s[cur].insert(v[cur]);
        int prv = 0;
        for(int nxt : e[cur]){
            dfs(nxt);
            prv = max(prv, ans[nxt-1]);
            if(s[nxt].size() > s[cur].size()) s[cur].swap(s[nxt]);
            for(int nv : s[nxt]) s[cur].insert(nv);
        }
        while(s[cur].count(prv)) prv++;
        ans[cur-1] = prv;
    };
    dfs(root);
    for(int i : ans) cout << i << '\n';
    return 0;
}