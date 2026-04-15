#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    if(n == 1) return !(cout << 0);
    if(n < 5) return !(cout << (n == 2 || n == 3 ? 1 : 0));
    int size = n/3+1;
    bool isp[size]; memset(isp, 1, sizeof(isp));
    isp[0] = 0;
    for(int i = 1; i*i <= n; i++){
        if(isp[i]){
            int p = 3*i+1|1;
            int d = p*2;
            int s = p*p;
            int j = p*(p+4-2*(i&1));
            for(int k = s/3; k < size; k += d) isp[k] = 0;
            for(int k = j/3; k < size; k += d) isp[k] = 0;
        }
    }
    vector<int> primes = {2, 3};
    for(int i = 1; i < size; i++) if(isp[i]) primes.push_back(3*i+1|1);
    int ans, sp, l; ans = sp = l = 0;
    for(int rp : primes){
        sp += rp;
        while(sp > n) sp -= primes[l++];
        if(sp == n) ans++;        
    }
    cout << ans;
    return 0;
}