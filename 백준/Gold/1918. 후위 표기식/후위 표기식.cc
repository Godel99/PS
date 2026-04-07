#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    unordered_map<char, int> pri ={{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};
    stack<char> st;
    for(char c : s){
        if('A' <= c && c <= 'Z') cout << c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(st.size() && st.top() != '('){
                cout << st.top(); st.pop();
            }
            st.pop();
        }
        else{
            while(st.size() && pri[st.top()] >= pri[c]){
                cout << st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(st.size()){
        cout << st.top(); st.pop();
    }
    return 0;
} 