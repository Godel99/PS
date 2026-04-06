#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> matrix;

const ll MOD = 1'000'000'007;

matrix mul(matrix& a, matrix& b){
    matrix ret(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; i++) for(int k = 0; k < 2; k++) for(int j = 0; j < 2; j++){
        ret[i][j] = (ret[i][j]+a[i][k]*b[k][j])%MOD;
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    if(n == 0) return !(cout << 0);
    matrix base = {{1, 1}, {1, 0}};
    matrix ans = {{1, 0}, {0, 1}};
    while(n){
        if(n&1) ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    cout << ans[0][1];
    return 0;
} 