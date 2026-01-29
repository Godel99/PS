#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> l(n);
    for(int i = 0; i < n; i++) cin >> l[i].first >> l[i].second;
    sort(l.begin(), l.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& [p, d]: l){
        pq.push(p);
        if(pq.size() > d) pq.pop();
    }
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}