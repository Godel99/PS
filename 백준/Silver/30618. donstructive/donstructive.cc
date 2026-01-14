#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i+=2) cout << i << ' ';
	for(int i = n - n%2; i; i -= 2) cout << i << ' ';
    return 0;
}