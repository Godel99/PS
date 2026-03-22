#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    vector<vector<array<int,2>>> dp(n, vector<array<int,2>>(m, {0, 0}));
    dp[0][0][0] = 1;
    deque<ai3> dq;
    dq.push_back({0, 0, 0});
    while(!dq.empty()){
        auto[x, y, b] = dq.front(); dq.pop_front();
        if(x == n-1 && y == m-1) return !(cout << dp[x][y][b]);
        for(int dir = 0; dir < 4; dir++){
            int nx = x+dx[dir], ny = y+dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(board[nx][ny] == '0' && dp[nx][ny][b] == 0){
                dp[nx][ny][b] = dp[x][y][b]+1;
                dq.push_back({nx, ny, b});
            }
            if(board[nx][ny] == '1' && b == 0 && dp[nx][ny][1] == 0){
                dp[nx][ny][1] = dp[x][y][b]+1;
                dq.push_back({nx, ny, 1});
            }
        }
    }
    cout << -1;
    return 0;
}