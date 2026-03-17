#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), [](string& x, string& y){
        return x+y > y+x;
    });
    if(a[0] == "0"){cout << 0; return 0;}
    for(string s : a) cout << s;
    return 0;
}