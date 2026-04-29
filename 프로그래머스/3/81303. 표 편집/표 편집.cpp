#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

string solution(int n, int k, vector<string> cmd) {
    vector<int> pre(n, -1), nxt(n, -1);
    vector<char> ans(n, 'O');
    stack<ai3> st;
    for(int i = 0; i < n; i++){
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    nxt[n-1] = -1;
    for(auto& c : cmd){
        if(c[0] == 'D'){
            int v = stoi(c.substr(2));
            while(v--) k = nxt[k];
        }
        else if(c[0] == 'U'){
            int v = stoi(c.substr(2));
            while(v--) k = pre[k];
        }
        else if(c[0] == 'C'){
            st.push({pre[k], k, nxt[k]});
            if(pre[k] != -1) nxt[pre[k]] = nxt[k];
            if(nxt[k] != -1) pre[nxt[k]] = pre[k];
            if(nxt[k] == -1) k = pre[k];
            else k = nxt[k];
        }
        else{
            auto [pi, cur, ni] = st.top(); st.pop();
            if(pi != -1) nxt[pi] = cur;
            if(ni != -1) pre[ni] = cur;
        }
    }
    while(st.size()){
        auto [pi, cur, ni] = st.top(); st.pop();
        ans[cur] = 'X';
    }
    return string(ans.begin(), ans.end());
}