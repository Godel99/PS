#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<string> ans;

void gcd(int a, int b){
    if(!a) return;
    if(a == b) return ans.push("cos");
    if(a > b){
        ans.push("tan");
        ans.push("acos");
        ans.push("sin");
        ans.push("atan");
        return gcd(b, a);
    }
    ans.push("sin");
    ans.push("atan");
    return gcd(a, b-a);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    a *= a; b *= b;
    gcd(a, b);
    cout << ans.size() << '\n';
    while(ans.size()){
        cout << ans.top() << ' '; ans.pop();
    }
    return 0;
}