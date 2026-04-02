#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int R, C, T, clean = -1;
vector<vector<int>> room;

void spread(){
    vector<vector<int>> tmp(R, vector<int>(C, 0));
    for(int r = 0; r < R; r++) for(int c = 0; c < C; c++){
        if(room[r][c] > 0){
            int a = room[r][c]/5, cnt = 0;
            if(!a) continue;
            for(int d = 0; d < 4; d++){
                int nr = r+dr[d], nc = c+dc[d];
                if(0 <= nr && nr < R && 0 <= nc && nc < C && room[nr][nc] != -1){
                    tmp[nr][nc] += a;
                    cnt++;

                }
            }
            room[r][c] -= a*cnt;
        }
    }
     for(int r = 0; r < R; r++) for(int c = 0; c < C; c++) room[r][c] += tmp[r][c];
}

void rot_top(int top){
    for(int r = top-1; r > 0; r--) room[r][0] = room[r-1][0];
    for(int c = 0; c < C-1; c++) room[0][c] = room[0][c+1];
    for(int r = 0; r < top; r++) room[r][C-1] = room[r+1][C-1];
    for(int c = C-1; c > 1; c--) room[top][c] = room[top][c-1];
    room[top][1] = 0;
}

void rot_bot(int bot){
    for(int r = bot+1; r < R-1; r++) room[r][0] = room[r+1][0];
    for(int c = 0; c < C-1; c++) room[R-1][c] = room[R-1][c+1];
    for(int r = R-1; r > bot; r--) room[r][C-1] = room[r-1][C-1];
    for(int c = C-1; c > 1; c--) room[bot][c] = room[bot][c-1];
    room[bot][1] = 0;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> R >> C >> T;
    room.resize(R, vector<int>(C));
    for(int r = 0; r < R; r++) for(int c = 0; c < C; c++) cin >> room[r][c];
    for(int r = 0; r < R; r++) if(room[r][0] == -1){clean = r; break;}
    while(T--){
        spread();
        rot_top(clean);
        rot_bot(clean+1);
    }
    int ans = 0;
    for(int r = 0; r < R; r++) for(int c = 0; c < C; c++) ans += room[r][c];
    cout << ans+2;
    return 0;
}