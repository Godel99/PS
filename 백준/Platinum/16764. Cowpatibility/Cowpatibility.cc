#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ai5 = array<int, 5>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ai5> v; v.reserve(n*31);
    for(int i = 0; i < n; i++){
        ai5 id; cin >> id[0] >> id[1] >> id[2] >> id[3] >> id[4];
        sort(id.begin(), id.end());
        for(int j = 1; j < 32; j++){
            ai5 a = {0,}; int idx = 0;
            for(int k = 0; k < 5; k++) if(j>>k & 1) a[idx++] = id[k];
            v.push_back(a);  
        }
    }
    sort(v.begin(), v.end());
    ll ans = (ll)n*(n-1)/2, cnt = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]) cnt++;
        else{
            int sz = 0;
            while(sz < 5 && v[i-1][sz] != 0) sz++;
            ans += (sz&1 ? -1 : 1)*cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    int sz = 0;
    while(sz < 5 && v.back()[sz] != 0) sz++;
    ans += (v.back().size()&1 ? -1 : 1)*cnt*(cnt-1)/2;
    cout << ans;
    return 0;
} 