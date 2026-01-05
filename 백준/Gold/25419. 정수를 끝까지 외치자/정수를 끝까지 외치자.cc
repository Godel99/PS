#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    cin.ignore(); 

    vector<bool> dp(n + 1, false);
    vector<bool> blocked(n + 1, false);   

    string line;
    getline(cin, line);
    stringstream ss(line);
    int b;
    while (ss >> b) {
        if (b <= n) {
            blocked[b] = true;
        }
    }
    for (int x = n; x > -1; x--){
        for (int d = 1; d < k+1; d++){
            int y=x+d;
            if (y>n) continue;
            if (blocked[y]) continue;
            if (!dp[y]){
                dp[x] = true;
                break;
            }
        }
    }
    for (int i = 1; i < k+1; i++){
        if (i > n) continue;
        if (blocked[i]) continue;
        if (!dp[i]){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}