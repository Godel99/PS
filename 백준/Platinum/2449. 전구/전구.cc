#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> b(n), a;
    for(int i = 0; i < n; i++) cin >> b[i];
    a.push_back(b[0]);
    for(int i = 1; i < n; i++) if(b[i] != b[i-1]) a.push_back(b[i]);
    int m = a.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for(int d = 1; d < m; d++){
        for(int l = 0; l < m-d; l++){
            int r = l+d, mind = d;
            for(int mid = l; mid < r; mid++){
                mind = min(mind, dp[l][mid]+dp[mid+1][r]+(a[l] != a[mid+1]));
            }
            dp[l][r] = mind;
        }
    }
    cout << dp[0][m-1];
    return 0;
}