#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> score(2, vector<int>(n));
        for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> score[i][j];
        if(n == 1){cout << max(score[0][0], score[1][0]) << '\n'; continue;}
        score[0][1] += score[1][0];
        score[1][1] += score[0][0];
        for(int i = 2; i < n ; i++){
            score[0][i] += max(score[1][i-1], score[1][i-2]);
            score[1][i] += max(score[0][i-1], score[0][i-2]);
        }
        cout << max(score[0][n-1], score[1][n-1]) << '\n';
    }
    return 0;
}