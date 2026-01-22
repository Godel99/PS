#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[10];

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string n; cin >> n;
    for(auto c: n) cnt[c-'0']++;
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < cnt[i]; j++) cout << i;
    }
	return 0;
}