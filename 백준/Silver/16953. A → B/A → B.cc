#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    int cnt = 1;
    while(b > a){
        if(b%2 == 0) b >>= 1;
        else if(b%10 == 1) b /= 10;
        else break;
        cnt++;
    }
    cout << (b == a ? cnt : -1);
    return 0;
}