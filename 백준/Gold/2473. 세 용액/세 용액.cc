#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using al3 = array<ll, 3>;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll minv = LLONG_MAX;
    al3 ans;
    for(int i = 0; i < n-2; i++){
        int l = i+1, r = n-1;
        while(l < r){
            ll v = a[i]+a[l]+a[r];
            if(minv > abs(v)){
                minv = abs(v);
                ans = {a[i], a[l], a[r]};
                if(minv == 0) return !(cout << ans[0] << ' ' << ans[1] << ' ' << ans[2]);
            }
            if(v < 0) l++;
            else r--;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}