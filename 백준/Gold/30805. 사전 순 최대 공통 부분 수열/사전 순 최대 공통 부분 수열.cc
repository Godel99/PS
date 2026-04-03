#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m; vector<int> b(m); for(int i = 0; i < m; i++) cin >> b[i];
    int maxl = 0;
    for(int i = 0; i < n; i++) maxl = max(maxl, a[i]);
    for(int i = 0; i < m; i++) maxl = max(maxl, b[i]);
    vector<int> ans;
    auto acur = a.begin(), bcur = b.begin();
    for(int x = maxl; x > 0; x--){
        while(1){
            auto anxt = find(acur, a.end(), x), bnxt = find(bcur, b.end(), x);
            if(anxt == a.end() || bnxt == b.end()) break;
            ans.push_back(x);
            acur = next(anxt); bcur = next(bnxt);
        }
    }
    cout << (int)ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}