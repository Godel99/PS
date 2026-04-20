#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> s(n+1, 0);
        for(int i = 1; i <= n; i++) cin >> s[i];
        int cnt = 0;
        vector<bool> vis(n+1, 0), fin(n+1, 0);
        function<void(int)> dfs = [&](int cur){
            vis[cur] = 1;
            int nxt = s[cur];
            if(!vis[nxt]) dfs(nxt);
            else if(!fin[nxt]){
                for(int i = nxt; i != cur; i = s[i]) cnt++;
                cnt++;
            }
            fin[cur] = 1;
        };
        for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
        cout << n - cnt << '\n';
    }
    return 0;
}