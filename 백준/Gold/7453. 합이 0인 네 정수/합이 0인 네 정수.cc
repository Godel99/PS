#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    const int SIZE = 1'048'576;
    int n, AB, CD, cnt, LM; cin >> n;
    vector<int> A(n), B(n), C(n), D(n), NB(n, 0), ND(n, 0);
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        C[i] = -C[i], D[i] = -D[i];
    }
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); sort(C.begin(), C.end()); sort(D.begin(), D.end());
    AB = CD = cnt = 0;
    LM = min(A[0]+B[0], C[0]+D[0])+SIZE-1;
    vector<int> RK(SIZE, 0), RS(SIZE, 0);
    ll ans = 0;
    while(AB < n && CD < n){
        cnt++;
        for(int i = AB; i < n; i++){
            int l = LM-A[i];
            while(NB[i] < n){
                int s = l-B[NB[i]];
                if(s < 0) break;
                if(RK[s] == cnt) RS[s]++;
                else RK[s] = cnt, RS[s] = 1;
                NB[i]++;
                if(NB[i] == n) AB++;
            }
        }
        for(int i = CD; i < n; i++){
            int l = LM-C[i];
            while(ND[i] < n){
                int s = l-D[ND[i]];
                if(s < 0) break;
                if(RK[s] == cnt) ans += RS[s];
                ND[i]++;
                if(ND[i] == n) CD++;
            }
        }
        LM += SIZE;
    }
    cout << ans;
    return 0;
}