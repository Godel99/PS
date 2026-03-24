#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int m; cin >> m;
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];
    int pre = p[0], pcnt, ncnt, ans; pcnt = ncnt = ans = 1;
    for(int i = 1; i < m; i++){
        if(pre == p[i]) continue;
        if(pre > p[i]){
            ncnt++; pcnt = 1;
        }
        else{
            pcnt++; ncnt = 1;
        }
        pre = p[i];
        ans = max({ans, pcnt, ncnt});
    }
    cout << ans;
    return 0;
} 