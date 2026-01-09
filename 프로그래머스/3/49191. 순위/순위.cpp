#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n, vector<vector<int>> results) {
    vector<bitset<101>> win(n);
    for(auto &r : results){
        int a = r[0] - 1;
        int b = r[1] - 1;
        win[a][b] = 1;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(win[i][k]) win[i] |= win[k];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int wins = win[i].count();
        int losses = 0;

        for(int j = 0; j < n; j++){
            if(win[j][i]) losses++;
        }
        
        if(wins + losses == n - 1) ans++;
    }
    return ans;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    return 0;
}