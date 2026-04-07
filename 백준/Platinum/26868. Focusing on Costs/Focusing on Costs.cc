#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    a *= a; b *= b;
    stack<string> ans;
    while(a != b){
        if(a < b){
            b -= a;
            ans.push("sin");
            ans.push("atan");
        }
        else{
            swap(a, b);
            ans.push("tan");
            ans.push("acos");
            ans.push("sin");
            ans.push("atan");
        }
    }
    ans.push("cos");
    cout << ans.size() << '\n';
    while(ans.size()){
        cout << ans.top() << ' '; ans.pop();
    }
    return 0;
}