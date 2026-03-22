#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using piv = pair<int, vector<int>>;

piv f(int n, int k){
    vector<int> path;
    if(n >= k){
        for(int i = n; i >= k; i--) path.push_back(i);
        return {n-k, path};
    }
    if(k == 1) return {1, {0, 1}};
    if(k&1){
        auto [a, b] = f(n, k-1);
        auto [c, d] = f(n, k+1);
        if(a < c){
            b.push_back(k);
            return {a+1, b};
        }
        else{
            d.push_back(k);
            return {c+1, d};
        }
    }
    else{
        auto [a, b] = f(n, k/2);
        if(k-n < a+1){
            for(int i = n; i <= k; i++) path.push_back(i);
            return {k-n, path};
        }
        else{
            b.push_back(k);
            return {a+1, b};
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    auto [time, path] = f(n, k);
    cout << time << '\n';
    for(int i: path) cout << i << ' ';
    return 0;
} 