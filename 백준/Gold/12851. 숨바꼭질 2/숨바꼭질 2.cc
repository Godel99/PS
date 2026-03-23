#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

pii f(int n, int k){
    if(n >= k) return {n-k, 1};
    if(k == 1) return {1, 1};
    if(k&1){
        auto [a, b] = f(n, ~-k);
        auto [c, d] = f(n, -~k);
        if(a == c) return {-~a, b+d};
        else if(a < c) return {-~a, b};
        else return {-~c, d};
    }
    else{
        auto [a, b] = f(n, k>>1);
        if(k-n == a+1) return {k-n, -~b};
        else if(k-n < a+1) return {k-n, 1};
        else return {-~a, b};
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    auto [t, c] = f(n, k);
    cout << t << '\n' << c;
    return 0;
} 