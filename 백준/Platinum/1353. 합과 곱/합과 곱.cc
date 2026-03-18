#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int s, p, n; cin >> s >> p; n = 2;
    if(s == p) return !(cout << 1);
    double d = 0;
    while(true){
        double m = pow(1.0*s/n, n);
        if(m >= p) return !(cout << n);
        if(m < d) return !(cout << -1);
        d = m;
        n++;
    }
    return 0;
} 