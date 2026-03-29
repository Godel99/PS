#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, maxV; cin >> n; maxV = n+1;
    bool isp[maxV]; memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    for(int i = 2; i*i <= maxV; i++){
        if(isp[i]) for(int j = i*i; j <= maxV; j+=i) isp[j] = 0;
    }
    int R = n;
    vector<pll> ans; ans.reserve(n/2);
    while(R > 7){
        bool flag = 0;
        for(int LL = R-1; LL > 0; LL--) if((LL+R)%3 == 0 && (LL+R)&1){
            for(int L = LL; L > 0; L -=6) if(isp[(L+R)/3]){
                for(int i = 0; i < (R-L+1)/2; i++) ans.push_back({L+i, R-i});
                R = L-1;
                flag = 1;
                break;
            }
            if(flag) break;
        }
    }
    if(R >= 6) ans.insert(ans.end(), {{1, 5}, {2, 4}, {3, 6}});
    else if(R >= 4) ans.insert(ans.end(), {{1, 3}, {2, 4}});
    else if(R == 3) ans.push_back({1, 3});
    cout << ans.size() << '\n';
    for(auto& [x, y] : ans) cout << x << ' ' << y << '\n';
    return 0;
} 