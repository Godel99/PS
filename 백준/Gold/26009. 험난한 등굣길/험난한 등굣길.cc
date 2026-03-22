#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
vector<vector<bool>> visited;
int n, m;

void mark_blocked(int r, int c, int d){
    for(int i = 0; i <= d; i++){
        int j = d-i;
        int tr[] = {r+i, r+i, r-i, r-i}, tc[] = {c+j, c-j, c+j, c-j};
        for(int k = 0; k < 4; k++){
            if(1 <= tr[k] && tr[k] <= n && 1 <= tc[k] && tc[k] <= m && !visited[tr[k]][tc[k]]) visited[tr[k]][tc[k]] = 1;
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int k;
    cin >> n >> m >> k;
    visited.assign(n+1, vector<bool>(m+1, 0));
    for(int i = 0; i < k; i++){
        int r, c, d; cin >> r >> c >> d;
        mark_blocked(r, c, d);
    }
    queue<ai3> q; q.push({1, 1, 0});
    visited[1][1] = 1;
    while(q.size()){
        auto [r, c, d] = q.front(); q.pop();
        if(r == n && c == m) return !(cout << "YES\n" << d);
        for(int dir = 0; dir < 4; dir++){
            int nr = r+dr[dir], nc = c+dc[dir];
            if(1 <= nr && nr <= n && 1 <= nc && nc <= m && !visited[nr][nc]){
                visited[nr][nc] = 1;
                q.push({nr, nc, d+1});
            }
        }
    }
    cout << "NO";
    return 0;
} 