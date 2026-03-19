#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int maxdp[] = {a, b, c}, mindp[] = {a, b, c};
    while(--n){
        int na, nb, nc; cin >> na >> nb >> nc;
        int pmaxa = maxdp[0], pmaxb = maxdp[1], pmaxc = maxdp[2];
        int pmina = mindp[0], pminb = mindp[1], pminc = mindp[2];
        maxdp[0] = max(pmaxa, pmaxb)+na, maxdp[1] = max({pmaxa, pmaxb, pmaxc})+nb, maxdp[2] = max(pmaxb, pmaxc)+nc;
        mindp[0] = min(pmina, pminb)+na, mindp[1] = min({pmina, pminb, pminc})+nb, mindp[2] = min(pminb, pminc)+nc;
    }
    cout << max({ maxdp[0],  maxdp[1],  maxdp[2]}) << ' ' << min({ mindp[0],  mindp[1],  mindp[2]});
    return 0;
} 