#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> dp(k+1, 0);
    while(n--){
        int w, v; cin >> w >> v;
        if(w > k) continue;
        for(int i = k; i >= w; i--) dp[i] = max(dp[i], dp[i-w]+v);
    }
    cout << dp[k];
    return 0;
} 