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
        vector<int> deg(n+1, 0);
        for(int i = 1; i <= n; i++) deg[s[i]]++;
        stack<int> st;
        for(int i = 1; i <= n; i++) if(deg[i] == 0) st.push(i);
        int ans = 0;
        while(st.size()){
            int cur = st.top(); st.pop();
            ans++;
            int nxt = s[cur];
            deg[nxt]--;
            if(deg[nxt] == 0) st.push(nxt);
        }
        cout << ans << '\n';
    }
    return 0;
}