#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

ll pw(ll n, ll r){
	ll ret = 1;
	while(r){
		if(r&1) ret = ret*n%MOD;
		n = n*n%MOD;
		r>>=1;
	}
	return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> A(n);
        int mx = -3, mxcnt = -1, cnt[2] = {0, 0}, minus = 0, minustwo = 0;
        bool flag = 0;
        for(int i = 0; i < n; i++){
            cin >> A[i]; int x = A[i];
            mx = max(mx, x);
            if(x > 0) flag = 1;
            if(x > 1) cnt[minus]++;
            if(x < 0) minus++;
            if(x < -1) minustwo++;
            if(minus == 2){
                flag = 1;
                cnt[0] += minustwo+cnt[1];
                cnt[1] = minustwo = minus = 0;
            }
            if(flag) mxcnt = max({mxcnt, cnt[0], cnt[1]});
            if(!x) flag = cnt[0] = cnt[1] = minus = minustwo = 0;
        }
        if(mxcnt < 0){
            cout << mx << '\n'; continue;
        }
        cnt[0] = cnt[1] = minus = minustwo = 0;
        for(int i = 0; i < n; i++){
            int x = A[n-i-1];
            if(x > 0) flag = 1;
            if(x > 1) cnt[minus]++;
            if(x < 0) minus++;
            if(x < -1) minustwo++;
            if(minus == 2){
                flag = 1;
                cnt[0] += minustwo+cnt[1];
                cnt[1] = minustwo = minus = 0;
            }
            if(flag) mxcnt = max({mxcnt, cnt[0], cnt[1]});
            if(!x) flag = cnt[0] = cnt[1] = minus = minustwo = 0;
        }
        cout << pw(2, mxcnt) << '\n';
    }
    return 0;
}