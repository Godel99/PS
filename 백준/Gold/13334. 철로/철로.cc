#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, d; cin >> n;
    vector<pii> route(n);
    for(int i = 0; i < n; i++){
        int s, e; cin >> s >> e;
        if(s > e) swap(s, e);
        route[i] = {s, e};
    }
    cin >> d;
    sort(route.begin(), route.end(), [](const pii& a, const pii& b){
        return a.second < b.second;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for(auto [s, e] : route){
        if(abs(s-e) > d) continue;
        pq.push(s);
        while(pq.size() && pq.top() < e-d) pq.pop();
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}