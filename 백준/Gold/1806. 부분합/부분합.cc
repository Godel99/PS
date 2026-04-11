#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = INT_MAX, l = 0, suma = 0;
    for(int r = 0; r < n; r++){
        suma += a[r];
        while(suma >= s){
            ans = min(ans, r-l+1);
            suma -= a[l];
            l++;
        }
    }
    cout << (ans == INT_MAX ? 0 : ans);
    return 0;
}