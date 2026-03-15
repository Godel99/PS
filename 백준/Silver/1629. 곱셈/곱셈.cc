#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll c){
    if(b == 0) return 1;
    if(b == 1) return a%c;
    ll half = pow(a, b>>1, c);
    half = (half*half)%c;
    if(b&1) return (half*(a%c))%c;
    else return half;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll a, b, c; cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}