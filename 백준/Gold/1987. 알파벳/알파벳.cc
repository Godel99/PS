#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int r, c, maxdist = 1;
vector<vector<int>> board;

void dfs(int x, int y, int bit, int dist){
    maxdist = max(maxdist, dist);
    if(maxdist == 26) return;
    for(int dir = 0; dir < 4; dir++){
        int nx = x+dx[dir], ny = y+dy[dir];
        if(0 <= nx && nx < r && 0 <= ny && ny < c && !(bit&1<<board[nx][ny])){
            int nbit = bit|1<<board[nx][ny];
            dfs(nx, ny, nbit, dist+1);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> r >> c; board.resize(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        string row; cin >> row;
        for(int j = 0; j < c; j++) board[i][j] = row[j]-'A';
    }
    dfs(0, 0, 1<<board[0][0], 1);
    cout << maxdist;
    return 0;
} 