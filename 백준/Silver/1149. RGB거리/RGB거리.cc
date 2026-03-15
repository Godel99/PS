#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int r, g, b; cin >> r >> g >> b;
    for(int i = 0; i < n-1; i++){
        int nr, ng, nb; cin >> nr >> ng >> nb;
        int pr = r, pg = g, pb = b;
        r = min(pg, pb)+nr, g = min(pr, pb)+ng, b = min(pr, pg)+nb;
    }
    cout << min({r, g, b});
    return 0;
}