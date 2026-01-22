#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[10001];

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        cnt[m]++;
    }
    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < cnt[i]; j++) cout << i << '\n';
    }
	return 0;
}