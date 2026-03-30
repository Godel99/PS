#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> up(n, 1), down(n, 1);
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++){
        if(a[j] < a[i]) up[i] = max(up[i], up[j]+1);
    }
    for(int i = n-1; i >= 0; i--) for(int j = i+1; j < n; j++){
        if(a[j] < a[i]) down[i] = max(down[i], down[j]+1);
    }
    int ans = 1;
    for(int i = 0; i < n; i++) ans = max(ans, up[i]+down[i]-1);
    cout << ans;
    return 0;
} 