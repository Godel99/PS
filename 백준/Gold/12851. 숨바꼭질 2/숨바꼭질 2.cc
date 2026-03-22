#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    if(n ==  k) return !(cout << 0 << '\n' << 1);
    int maxl = max(n, k)+2;
    vector<int> dp(maxl, -1);
    dp[n] = 0;
    queue<int> q; q.push(n);
    int cnt = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        if(cur == k){
            cnt++;
            continue;
        }
        for(auto nxt: {cur-1, cur+1, cur*2}){
             if(0 <= nxt && nxt < maxl && (dp[nxt] == -1 || dp[nxt] == dp[cur]+1)){
                dp[nxt] = dp[cur]+1;
                q.push(nxt);
             }
        }
    }
    cout << dp[k] << '\n' << cnt;
    return 0;
} 