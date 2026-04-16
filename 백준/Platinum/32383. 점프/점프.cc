#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> h(n), ch(n, 1);
    for(int i = 0; i < n; i++) cin >> h[i];
    stack<int> st;
    ll ans = 0;
    for(int r = 0; r < n; r++){
        while(st.size() && h[st.top()] <= h[r]){
            int l = st.top(); st.pop();
            int m = (st.size() && h[st.top()] < h[r] ? st.top() : r);
            ll dif = h[m]-h[l];
            ll way = (ll)(n-ch[l])*ch[l]%MOD;
            ll cst = dif*dif%MOD;
            ans = (ans+way*cst)%MOD;
            ch[m] += ch[l];
        }
        st.push(r);
    }
    while(st.size() > 1){
        int r = st.top(); st.pop();
        int l = st.top();
        ll dif = h[l]-h[r];
        ll way = (ll)(n-ch[r])*ch[r]%MOD;
        ll cst = dif*dif%MOD;
        ans = (ans+way*cst)%MOD;
        ch[l] += ch[r];
    }
    cout << ans;
    return 0;
}