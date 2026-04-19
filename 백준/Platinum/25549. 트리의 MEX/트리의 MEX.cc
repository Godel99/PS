#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int root;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        if (p < 0) root = i;
        else adj[p].push_back(i);
    }
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> ans(n);
    function<void(int, int&, set<int>&)> dfs = [&](int u, int& mex, set<int>& s) {
        s.insert(a[u]);
        for (int v : adj[u]) {
            int cmex = 0;
            set<int> cs;
            dfs(v, cmex, cs);
            if (cs.size() > s.size()) swap(cs, s);
            mex = max(mex, cmex);
            for (int i : cs) s.insert(i);
        }
        while (s.count(mex)) mex++;
        ans[u] = mex;
    };  
    int mex = 0;
    set<int> s;
    dfs(root, mex, s);
    for (int i : ans) cout << i << '\n';
    return 0;
}