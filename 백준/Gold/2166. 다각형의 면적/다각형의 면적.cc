#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    v.push_back(v[0]);
    ll sumv = 0;
    for(int i = 0; i < n; i++) sumv += v[i].first*v[i+1].second-v[i+1].first*v[i].second;
    double area = abs(sumv)/2.0;
    cout << fixed << setprecision(1) << area;
    return 0;
} 