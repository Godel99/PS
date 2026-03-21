#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    if(n ==  k) return !(cout << 0);
    int maxl = max(n, k)+2;
    vector<int> dp(maxl, -1);
    dp[n] = 0;
    deque<int> dq; dq.push_back(n);
    while(dq.size()){
        int cur = dq.front(); dq.pop_front();
        if(cur == k) break;
        int nxt = cur*2;
        if(0 <= nxt && nxt < maxl && dp[nxt] == -1){
            dp[nxt] = dp[cur];
            dq.push_front(nxt);
        }
        for(auto nxt: {cur-1, cur+1}){
             if(0 <= nxt && nxt < maxl && dp[nxt] == -1){
                dp[nxt] = dp[cur]+1;
                dq.push_back(nxt);
             }
        }
    }
    cout << dp[k];
    return 0;
} 