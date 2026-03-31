#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int maxR = 1000001, maxX = 500000;
    bool isp[maxR+1]; memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    for(int i = 4; i <= maxR; i += 2) isp[i] = 0;
    for(int i = 3; i*i <= maxR+1; i += 2){
        if(isp[i]) for(int j = i*i; j <= maxR+1; j+=i*2) isp[j] = 0;
    }
    vector<int> ps(maxX+1, 0);
    for(int x = 1; x <= maxX; x++){
        if(isp[2*x+1]) ps[x] = ps[x-1]+1;
        else ps[x] = ps[x-1];
    }
    int q; cin >> q;
    while(q--){
        int L, R; cin >> L >> R;
        cout << ps[R-1]-ps[L-1] << '\n';
    }
    return 0;
}