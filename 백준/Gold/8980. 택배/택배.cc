#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using aiii = array<int, 3>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, c, m; cin >> n >> c >> m;
    vector<aiii> d(m);
    for(int i = 0; i < m; i++) cin >> d[i][0] >> d[i][1] >> d[i][2];
    sort(d.begin(), d.end(), [](const aiii& a, const aiii& b){
        return a[1] < b[1];
    });
    vector<int> cap(n+1, 0);
    int ans = 0;
    for(auto &[s, e, w]: d){
        int mx = 0;
        for(int i = s; i < e; i++) mx = max(mx, cap[i]);
        int can = min(w, c-mx);
        for(int i = s; i < e; i++) cap[i] += can;
        ans += can;
    }
    cout << ans;
    return 0;
}