#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<string> board(n);
    vector<vector<int>> vis(n , vector<int>(m, 0));
    for(int i = 0; i < n; i++) cin >> board[i];
    int ans, idx; ans = idx = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(vis[i][j]) continue;
        idx++;
        int x = i, y = j;
        while(!vis[x][y]){
            vis[x][y] = idx;
            if(board[x][y] == 'U') x--;
            else if(board[x][y] == 'D') x++;
            else if(board[x][y] == 'L') y--;
            else y++;
        }
        if(vis[x][y] == idx) ans++;
    }
    cout << ans;
    return 0;
}