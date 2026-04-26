#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N=100일 때 최대 칸 수는 10,000개, 그룹당 최대 5,000개
int n;
int adj[5005][4]; // 인접 리스트를 고정 배열로 하여 캐시 효율 증대
int adj_cnt[5005];
int mA[5005], mB[5005];
int vis[5005], timer;
bool isActive[2][5005];

struct Cell {
    int v, r, c, type, id;
    bool operator<(const Cell& o) const { return v < o.v; }
};

// DFS: 오직 Set 0의 정점에서만 시작함
bool dfs(int u) {
    vis[u] = timer;
    for (int i = 0; i < adj_cnt[u]; ++i) {
        int v = adj[u][i];
        if (!isActive[1][v]) continue; // 상대방 칸이 아직 활성화되지 않음
        
        if (!mB[v] || (vis[mB[v]] != timer && dfs(mB[v]))) {
            mA[u] = v;
            mB[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    vector<Cell> cells;
    int cnt[2] = {0, 0};
    int id_map[105][105];
    int type_map[105][105];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val; cin >> val;
            int type = (i + j) % 2;
            id_map[i][j] = ++cnt[type];
            type_map[i][j] = type;
            cells.push_back({val, i, j, type, id_map[i][j]});
        }
    }

    sort(cells.begin(), cells.end());

    // 간선 미리 계산 (Set 0에서 Set 1로 가는 단방향 간선만 저장)
    int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 != 0) continue; // Set 0만 기준으로 간선 생성
            int u = id_map[i][j];
            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k], nj = j + dc[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                adj[u][adj_cnt[u]++] = id_map[ni][nj];
            }
        }
    }

    vector<int> unmatched_A; // 아직 매칭되지 않은 Set 0 정점들
    int total_match = 0;
    int limit = n * n / 2;

    for (int i = 0; i < n * n; ++i) {
        int type = cells[i].type;
        int id = cells[i].id;
        isActive[type][id] = true;

        if (type == 0) unmatched_A.push_back(id);

        // 새로운 칸이 추가되었을 때 매칭이 늘어날 가능성이 있는지 확인
        // 매칭 시도는 항상 '매칭되지 않은' Set 0 정점들에서만 수행
        timer++;
        bool found = false;
        
        // 최적화: 새로 추가된 칸이 매칭을 발생시킬 수 있는 후보들만 조사
        for (int j = 0; j < (int)unmatched_A.size(); ++j) {
            int u = unmatched_A[j];
            if (dfs(u)) {
                // 매칭 성공 시 리스트에서 제거 (swap & pop_back)
                unmatched_A[j] = unmatched_A.back();
                unmatched_A.pop_back();
                found = true;
                total_match++;
                cout << cells[i].v << "\n";
                break;
            }
        }
        if (total_match == limit) break;
    }

    return 0;
}