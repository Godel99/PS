#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        a.push_back(k);
    }
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](const int& x, const int& y){
        return x > y;
    });
    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i]*b[i];
    cout << ans;
	return 0;
}
