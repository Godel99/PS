#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> ans;

void gcd(int a, int b){
    if(a == 0) return;
    if(a == b) return ans.push_back("cos");
    if(a > b){
        ans.insert(ans.end(), {"tan", "acos", "sin", "atan"});
        gcd(b, a);
        return;
    }
    ans.insert(ans.end(), {"sin", "atan"});
    gcd(a, b-a);
    return;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    a *= a; b *= b;
    gcd(a, b);
    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << ' ';
    return 0;
}