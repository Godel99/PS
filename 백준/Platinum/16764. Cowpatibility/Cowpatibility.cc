#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        int a[5]; cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        sort(a, a+5);
        for(int j = 1; j < 32; j++){
            vector<int> tmp;
            for(int k = 0; k < 5; k++) if(j>>k & 1) tmp.push_back(a[k]);
            v.push_back(tmp);  
        }
    }
    sort(v.begin(), v.end());
    ll ans = (ll)n*(n-1)/2, cnt = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]) cnt++;
        else{
            ans += (v[i-1].size()&1 ? -1 : 1)*cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += (v.back().size()&1 ? -1 : 1)*cnt*(cnt-1)/2;
    cout << ans;
    return 0;
} 