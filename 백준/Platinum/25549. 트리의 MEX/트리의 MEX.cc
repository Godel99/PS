#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> p(n+1, 0), v(n+1, 0), deg(n+1, 0), ans(n, 0);
    vector<vector<int>> e(n+1);
    vector<unordered_set<int>> s(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] == -1) continue;
        deg[p[i]]++;
        e[p[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> v[i];
    stack<int> st;
    for(int i = 1; i <= n; i++) if(deg[i] == 0) st.push(i);
    while(st.size()){
        int cur = st.top(); st.pop();
        s[cur].insert(v[cur]);
        int prv = 0;
        for(int nxt : e[cur]) prv = max(prv, ans[nxt-1]);
        for(int nv = prv; nv <= n; nv++) if(s[cur].find(nv) == s[cur].end()){
            ans[cur-1] = nv;
            break;
        }
        if(p[cur] == -1) continue;
        if(s[p[cur]].size() >= s[cur].size()) s[p[cur]].merge(s[cur]);
        else{ 
            s[cur].merge(s[p[cur]]);
            s[p[cur]] = move(s[cur]);
        }
        deg[p[cur]]--;
        if(deg[p[cur]] == 0) st.push(p[cur]);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}