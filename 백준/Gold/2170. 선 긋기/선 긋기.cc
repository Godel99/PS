#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pll> lines(n);
    for(int i = 0; i < n; i++) cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());
    ll start = lines[0].first, end = lines[0].second, total = 0;
    for(int i = 1; i < n; i++){
        ll s = lines[i].first;
        ll e = lines[i].second;
        if(s > end){
            total += end-start;
            start = s, end = e;
        }
        else end = max(end, e);
    }
    total += end-start;
    cout << total;
	return 0;
}