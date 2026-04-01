#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
vector<vector<int>> lab;
vector<pii> ety, vir;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void bfs(){
    vector<vector<int>> tmp = lab;
    queue<pii> q;
    for(auto v: vir) q.push(v);
    int cnt = 0;
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x+dx[dir], ny = y+dy[dir];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && !tmp[nx][ny]){
                tmp[nx][ny] = 1;
                cnt++;
                q.push({nx, ny});
            }
        }
    }
    ans = max(ans, (int)ety.size()-cnt-3);
}

void makewall(int cnt, int start){
    if(cnt == 3){bfs(); return;}
    for(int i = start; i < ety.size(); i++){
        auto [x, y] = ety[i];
        lab[x][y] = 1;
        makewall(cnt+1, i+1);
        lab[x][y] = 0;
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> m;
    lab.assign(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> lab[i][j];
        if(lab[i][j] == 0) ety.push_back({i, j});
        else if(lab[i][j] == 2) vir.push_back({i, j});
    }
    makewall(0, 0);
    cout << ans;
    return 0;
}