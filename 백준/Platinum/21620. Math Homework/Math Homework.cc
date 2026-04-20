#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<ai3> qry;
    vector<vector<int>> d(17, vector<int>(n+2, 0));
    while(m--){
        int x, y, z; cin >> x >> y >> z;
        qry.push_back({x, y, z});
        d[z][x]++;
        d[z][y+1]--;
    }
    vector<int> ans(n, 1);
    for(int z = 1; z <= 16; z++){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += d[z][i];
            if(cnt) ans[i-1] = lcm(ans[i-1], z);
        }
    }
    vector<int> tree(2*n, 0);
    for(int i = 0; i < n; i++) tree[n+i] = ans[i];
    for(int i = n-1; i > 0; i--) tree[i] = gcd(tree[i<<1], tree[i<<1|1]);
    for(auto [x, y, z] : qry){
        int res = 0, l = x+n-1, r = y+n-1;
        while(l <= r){
            if(l&1) res = gcd(res, tree[l++]);
            if(~r&1) res = gcd(res, tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        if(res != z) return !(cout << "Impossible");
    }
    for(int i : ans) cout << i << ' ';
    return 0;
}