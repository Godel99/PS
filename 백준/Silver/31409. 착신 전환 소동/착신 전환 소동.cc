#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1000001];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i++) cin >>a[i];
	for(int i = 1; i <= n; i++){
		if(a[i]==i){
			cnt++;
			a[i] = 1+(i==1);
		}
	}
	cout << cnt << '\n';
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}