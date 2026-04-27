#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ai5 = array<int, 5>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int n, timer = 0, maxn; cin >> n; maxn = n*n/2+1;
    vector<vector<int>> e(maxn), idx(n, vector<int>(n));
    vector<int> vis(maxn, 0), mA(maxn, 0), mB(maxn, 0);
    vector<ai5> cells;
    vector<vector<bool>> isAct(2, vector<bool>(maxn, 0));
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j){
        int x; cin >> x;
        int type = (i+j)%2;
        idx[i][j] = ++cnt[type];
        cells.push_back({x, i, j, type, idx[i][j]});
    }
    sort(cells.begin(), cells.end());
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j){
        if((i+j)%2) continue;
        for(int dir = 0; dir < 4; dir++){
            int ni = i+dx[dir], nj = j+dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            e[idx[i][j]].push_back(idx[ni][nj]);
        }
    }
    function<bool(int)> dfs = [&](int cur){
        vis[cur] = timer;
        if(!isAct[0][cur]) return false;
        for(int nxt : e[cur]){
            if(!isAct[1][nxt]) continue;
            if(!mB[nxt] || (vis[mB[nxt]] != timer && dfs(mB[nxt]))){
                mA[cur] = nxt;
                mB[nxt] = cur;
                return true;
            }
        }
        return false;
    };
    vector<int> unmatch;
    int total = 0, limit = n*n/2;
    for(int i = 0; i < n*n; i++){
        int x = cells[i][0];
        int type = cells[i][3];
        int id = cells[i][4];
        isAct[type][id] = 1;
        if(!type) unmatch.push_back(id);
        timer++;
        for(int j = 0; j < unmatch.size(); j++){
            if(dfs(unmatch[j])){
                unmatch[j] = unmatch.back(); unmatch.pop_back();
                cout << x << '\n';
                total++;
                break;
            }
        }
        if(total == limit) break;
    }
    return 0;
}