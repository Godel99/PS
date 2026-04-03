#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        a[i] = {v, i};
    }
    int m; cin >> m;
    vector<pii> b(m);
    for(int i = 0; i < m; i++){
        int v; cin >> v;
        b[i] = {v, i};
    }
    auto cmp = [](const pii& a, const pii& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    };
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    vector<int> ans;
    int lia, lib; lia = lib = -1;
    int pa, pb; pa = pb = 0;
    while(pa < n && pb < m){
        auto [va, ia] = a[pa];
        auto [vb, ib] = b[pb];
        if(va == vb){
            if(ia > lia && ib > lib){
                ans.push_back(va);
                lia = ia, lib = ib;
                pa++; pb++;
            }
            else{
                if(ia <= lia) pa++;
                else pb++;
            }
        }
        else if(va > vb) pa++;
        else pb++;
    }
    cout << (int)ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}