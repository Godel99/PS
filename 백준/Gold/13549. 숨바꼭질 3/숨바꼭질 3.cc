#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n, int k){
    if(n >= k) return n-k;
    if(k == 1) return abs(n-1);
    if(k&1) return -~min(f(n, k-1), f(n, k+1));
    else return min(k-n, f(n, k>>1));
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    cout << f(n, k);
    return 0;
} 