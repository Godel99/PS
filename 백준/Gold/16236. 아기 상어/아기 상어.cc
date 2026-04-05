#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
const int INF = 1e9;
int n;
vector<vector<int>> board;

ai3 getfish(int x, int y, int size){
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pii> q; q.push({x, y});
    dist[x][y] = 0;
    vector<ai3> can;
    int mind = INF;
    while(q.size()){
        auto [rx, ry] = q.front(); q.pop();
        if(dist[rx][ry] >= mind) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = rx+dx[dir], ny = ry+dy[dir];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && dist[nx][ny] == -1){
                if(board[nx][ny] <= size){
                    dist[nx][ny] = dist[rx][ry]+1;
                    if(0 < board[nx][ny] && board[nx][ny] < size){
                        mind = dist[nx][ny];
                        can.push_back({mind, nx, ny});
                    }
                    else q.push({nx, ny});
                }
            }
        }
    }
    if(can.size()) return *min_element(can.begin(), can.end());
    return {-1, -1, -1};
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    board.resize(n, vector<int>(n));
    int size = 2, time = 0, eat = 0;
    int x, y;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin >> board[i][j];
        if(board[i][j] == 9){ 
            x = i, y = j;
            board[i][j] = 0;
        }
    }
    while(1){
        ai3 sh = getfish(x, y, size);
        if(sh[0] == -1) break;
        auto [d, nx, ny] = sh;
        time += d;
        eat++;
        if(eat == size){
            size++;
            eat = 0;
        }
        board[nx][ny] = 0;
        x = nx, y = ny;
    }
    cout << time;
    return 0;
}