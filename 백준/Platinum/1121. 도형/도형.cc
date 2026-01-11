#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[55];
ll d[11][505050];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	d[0][0] = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int m; cin >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 50000*(m-1); j >= 0; j--){
			if(j <= a[i]) break;
			d[m][501010] += d[m-1][j];
		}
		for(int k = m-2; k >= 0; k--){
			for(int j = 50000*k; j >= 0; j--){
				d[k+1][j+a[i]] += d[k][j];
			}
		}
	}
	cout << d[m][501010];
}