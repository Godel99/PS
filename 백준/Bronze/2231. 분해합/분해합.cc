#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string n_str; cin >> n_str;
    int n = stoi(n_str);
    int start = max(0, n - 9 * (int)n_str.length());

    for (int i = start; i < n;  i++){
        int total = i;
        for(auto c : to_string(i)){
            total += (c-'0');
        }
        if (total == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
}