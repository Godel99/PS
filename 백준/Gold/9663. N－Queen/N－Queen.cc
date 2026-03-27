#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, cnt;
vector<bool> v1, v2, v3;

void dfs(int r){
    if(r == n){cnt++; return;}
    for(int c = 0; c < n; c++){
        if(v1[c] || v2[r+c] || v3[r-c+n]) continue;
        v1[c] = v2[r+c] = v3[r-c+n] = 1;
        dfs(r+1);
        v1[c] = v2[r+c] = v3[r-c+n] = 0;
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    v1.assign(n, 0); v2.assign(n*2, 0); v3.assign(n*3, 0);
    dfs(0);
    cout << cnt;
    return 0;
} 