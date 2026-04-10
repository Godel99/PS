#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    cout << "a=?max?\n";
    for(char c = 'b'; c <= 'p'; c++) cout << c << "=" << (char)(c-1) << "max" << (char)(c-1) << '\n';
    cout << "q=pmaxpmaxpmaxpmaxp\n";
    cout << "r=q/q\n";
    cout << "s=q-q\n";
    for(char c = 't'; c <= 'z'; c++){
        char pre = (c == 't') ? 'r' : (char)(c-1);
        cout << c << '=' << pre << '+' << pre << '\n';
    }
    if(n){
        vector<char> ans;
        char bit[] = {'r', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for(int i = 0; i < 8; i++) if(n & (1<<i)) ans.push_back(bit[i]);
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++) cout << '+' << ans[i];
    }
    else cout << 's';
    return 0;
}