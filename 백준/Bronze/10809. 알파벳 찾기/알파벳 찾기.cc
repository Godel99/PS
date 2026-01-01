#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;

    vector<int> alpha(26,-1);

    for(int i=0; i<s.length(); i++){
        int index = s[i] - 'a';
        if(alpha[index]==-1) alpha[index] = i;
    }
    for(int i=0; i<26; i++){
        cout << alpha[i] << (i == 25 ? "": " ");
    }
}