#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; string s; cin >> n >> s;
    int ans = 0;
    for(auto c : s) ans += c&1 ? 1 : -1;
    cout << -1+2*(ans>0)+(ans<0);
    return 0;
}