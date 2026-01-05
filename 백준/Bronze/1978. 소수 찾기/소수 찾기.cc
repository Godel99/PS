#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isprime(int n){
    if (n <= 1) return false;
    for (int i = 2; i < int(sqrt(n))+1; i++){
        if (n % i == 0) return false;  
    }
    return true;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (isprime(x)) cnt++;
    
    }
    cout << cnt;
}