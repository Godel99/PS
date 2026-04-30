#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<bool> dp(1<<n, 0);
    dp[1] = 1;
    int ans = 1;
    for(int mask = 1; mask < 1<<n; mask++){
        if(!dp[mask]) continue;
        int sheep = 0, wolf = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
                if(info[i]) wolf++;
                else sheep++;
            }
        }
        ans = max(ans, sheep);
        for(auto edge: edges){
            int p = edge[0], c = edge[1];
            if((mask & (1<<p)) && !(mask & (1<<c))){
                int nmask = mask | (1<<c);
                int nsheep = sheep+(!info[c]);
                int nwolf = wolf+(info[c]);
                if(nsheep > nwolf) dp[nmask] = 1;
            }
        }
    }
    return ans;
}