#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll pw(ll n){
    ll ret=1,a=2;
    while(n){
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    } return ret;
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll x = 0, n, l; cin >> n;
    l = n-n%255;
    for(ll i = l; i <= n; i++){
        x -= i; 
        if(x < 0) x = -x;
        if(i%3 == 0) x = (x%mod)*(i%mod)%mod;
        if(i%15 == 0) x &= i;
        if(i%63 == 0) x ^= i;
        if(i%255 == 0) x |= i;
        if(i%1023 == 0) x = x%mod*pw(i)%mod;
    } cout << x;
}