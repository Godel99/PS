#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int solution(int n, vector<int> money) {
    const ll MOD = 1'000'000'007;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int coin : money){
        for (int x = coin; x <= n; x++){
            dp[x] = (dp[x] + dp[x-coin]) % MOD;
        }
    }
    return dp[n];
}