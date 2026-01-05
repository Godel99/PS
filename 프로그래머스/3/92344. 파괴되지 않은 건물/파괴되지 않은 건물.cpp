#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
    
    for (auto s : skill){
        int t = s[0], r1= s[1], c1= s[2], r2= s[3], c2= s[4], d= s[5];
        
        if (t == 1) d = -d;

        diff[r1][c1] += d;
        diff[r1][c2+1] -= d;
        diff[r2+1][c1] -= d;
        diff[r2+1][c2+1] += d;
    }

    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j++) diff[i][j] += diff[i][j-1];
    }

    for (int j = 0; j < m; j++){
        for (int i = 1; i < n; i++) diff[i][j] += diff[i-1][j];
    }

    int answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] + diff[i][j] > 0) answer++;
        }
    }
    return answer;
}