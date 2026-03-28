#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    int n = t.length();
    char lc = t[n-1];
    string ans = "";
    for(char c : s){
        ans.push_back(c);
        if(c == lc && ans.size() >= n){
            bool flag = 1;
            for(int i = 0; i < n; i++) if(ans[ans.size()-n+i] != t[i]){
                flag = 0;
                break;
            }
            if(flag) for(int i = 0; i < n; i++) ans.pop_back();
        }
    }
    cout << (ans.size() ? ans : "FRULA");
    return 0;
} 