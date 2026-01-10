#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll S[4];

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int T; cin >> T; while(T--){
		cout << "YES\n";
		int n; cin >> n; S[0] = S[1] = S[2] = S[3] = 0;
		for(int i = 1; i <= n; i++){
			int t; cin >> t; S[i&3] += t;
		}
		ll m = min({S[0], S[1], S[2], S[3]});
		if(S[2] == m){
			cout << "0"; n--;
		}
		else if(S[3] == m){
			cout << "01"; n -= 2;
		}
		else if(S[0] == m){
			cout << "022"; n -= 3;
		}
		while(n >= 4){
			n -= 4; cout << "0333";
		}
		if(n) cout << 0;
		if(n == 2) cout << 1;
		if(n == 3) cout << 22;
		cout << '\n';
	}
}