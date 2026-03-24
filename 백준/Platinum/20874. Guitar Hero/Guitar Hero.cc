#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    vector<int> p(n), minR(n+1, n+1);
    for(int i = 0; i < n; i++) cin >> p[i];
    int L, inc, dec; L = 0; inc = dec = 1;
    for(int R = 1; R < n; R++){
        if(p[R] == p[R-1]) continue;
        if(p[R] > p[R-1]){
            if(dec > 1) L = R-1;
            dec = 1; inc++;
            if(inc > m){
                while(p[L] == p[L+1]) L++;
                if(minR[L+1] > R+1) minR[L+1] = R+1;
                L++; inc--;
            }
        }
        else{
            if(inc > 1) L = R-1;
            inc = 1; dec++;
            if(dec > m){
                while(p[L] == p[L+1]) L++;
                if(minR[L+1] > R+1) minR[L+1] = R+1;
                L++; dec--;
            }
        }
    }
    for(int i = n-1; i > 0; i--) minR[i] = min(minR[i], minR[i+1]);
    while(q--){
        int L, R; cin >> L >> R;
        if(minR[L] <= R) cout << "nej\n";
        else cout << "ja\n";
    }
    return 0;
} 