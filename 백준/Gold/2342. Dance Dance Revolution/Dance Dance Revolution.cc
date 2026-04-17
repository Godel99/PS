#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int cst(int start, int end){
    if(start == 0) return 2;
    if(start == end) return 1;
    if(abs(start-end) == 2) return 4;
    return 3;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int dp[5] = {0, INF, INF, INF, INF};
    int pre = 0, cur;
    while(cin >> cur && cur){
        int minv = INF;
        for(int i = 0; i < 5; i++){
            minv = min(minv, dp[i]+cst(i, cur));
            dp[i] += cst(pre, cur);
        }
        dp[pre] = minv;
        pre = cur;
    }
    cout << min({dp[0], dp[1], dp[2], dp[3], dp[4]});
    return 0;
}