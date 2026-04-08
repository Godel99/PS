#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long double E = 0.57721566490;
const int N = 10'000;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    vector<long double> dp(N+1, 0);
    for(int i = 1; i <= N; i++) dp[i] = dp[i-1]+(long double)1/i;
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        ll n; cin >> n;
        cout << "Case #" << i << ": ";
        cout << fixed << setprecision(12);
        if(n <= N) cout << dp[n];
        else cout << log(n)+E+1.0L/(2*n)-1.0L/(12.0L*n*n)+1.0L/(120.0L*n*n*n*n);
        cout << '\n';
    }
    return 0;
}