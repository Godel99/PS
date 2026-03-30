#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> LIS(const vector<int>& a){
    int n = a.size();
    vector<int> lst, ret(n, 0);
    for(int i = 0; i < n; i++){
        auto it = lower_bound(lst.begin(), lst.end(), a[i]);
        if(it == lst.end()) lst.push_back(a[i]);
        else *it = a[i];
        ret[i] = lst.size();
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> up = LIS(a);
    reverse(a.begin(), a.end());
    vector<int> down = LIS(a);
    reverse(down.begin(), down.end());
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, up[i]+down[i]-1);
    cout << ans;
    return 0;
} 