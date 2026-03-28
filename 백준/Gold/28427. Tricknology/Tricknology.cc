#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int maxR = 1000001, maxX = 500000;
    vector<bool> p(maxR+1, 1); p[0] = p[1] = 0;
    for(int i = 2; i*i <= maxR; i++){
        if(p[i]) for(int j = i*i; j <= maxR; j += i) p[j] = 0;
    }
    vector<int> ps(maxX+1, 0);
    for(int x = 1; x <= maxX; x++){
        if(p[2*x+1]) ps[x] = ps[x-1]+1;
        else ps[x] = ps[x-1];
    }
    int q; cin >> q;
    while(q--){
        int L, R; cin >> L >> R;
        cout << ps[R-1]-ps[L-1] << '\n';
    }
    return 0;
} 