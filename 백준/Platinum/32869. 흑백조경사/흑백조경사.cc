#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int N;
int C[MAXN];
vector<int> adj[MAXN];

int w[MAXN], b[MAXN]; // 서브트리 내 흰색, 검은색 정점 수
bool is_even[MAXN];    // 해당 정점을 루트로 하는 서브트리가 Even한지 여부
int ecnt[MAXN];       // 자식들 중 is_even이 false인 자식의 수
int tot_w, tot_b;
vector<int> ans;

// 현재 노드가 자손들의 색상 다수결 조건을 만족하는지 판별
// sub_w, sub_b는 현재 노드를 포함한 서브트리의 색상 수
bool check_self(int color, int sub_w, int sub_b) {
    int desc_w = sub_w - (color == 0 ? 1 : 0);
    int desc_b = sub_b - (color == 1 ? 1 : 0);
    if (desc_w > desc_b && color != 0) return false;
    if (desc_b > desc_w && color != 1) return false;
    return true;
}

// 1단계: 1번 노드를 루트로 하여 기본적인 트리 정보 수집
void dfs_init(int u, int p) {
    is_even[u] = true;
    w[u] = (C[u] == 0 ? 1 : 0);
    b[u] = (C[u] == 1 ? 1 : 0);
    ecnt[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_init(v, u);
        w[u] += w[v];
        b[u] += b[v];
        
        if (!is_even[v]) {
            is_even[u] = false;
            ecnt[u]++;
        }
    }
    // 자식 서브트리가 모두 Even해도, 자기 자신이 다수결을 어기면 Even하지 않음
    if (!check_self(C[u], w[u], b[u])) is_even[u] = false;
}

// 2단계: 리루팅 탐색 및 가지치기
void solve(int u, int p) {
    // 현재 u를 루트로 했을 때 전체 나무가 Even한지 확인
    // 1. 자식들 중 Even하지 않은 것이 없어야 함 (ecnt[u] == 0)
    // 2. 루트 정점 스스로가 전체 다수결 조건을 만족해야 함
    if (ecnt[u] == 0 && check_self(C[u], tot_w, tot_b)) {
        ans.push_back(u);
    }

    // [최적화 핵심: 가지치기]
    // Even하지 않은 자식이 2개 이상이라면, 어느 쪽으로 루트를 옮겨도 
    // 반대편에 Even하지 않은 서브트리가 남게 되므로 답이 될 수 없음.
    if (ecnt[u] >= 2) return;

    for (int v : adj[u]) {
        if (v == p) continue;

        // [가지치기 2]
        // Even하지 않은 자식이 딱 1개 있다면, 그 자식 방향으로만 가야 답의 가능성이 있음.
        if (ecnt[u] == 1 && is_even[v]) continue;

        // 루트를 v로 옮기기 위해 u(부모였던 쪽)가 Even한지 판별
        int up_w = tot_w - w[v];
        int up_b = tot_b - b[v];
        // u의 새로운 '자식'들이 모두 Even하고(ecnt[u]에서 v 제외), u 스스로 만족하는지
        int v_idx_bad = is_even[v] ? 0 : 1;
        if (ecnt[u] - v_idx_bad == 0 && check_self(C[u], up_w, up_b)) {
            // 이 조건이 맞아야 v 방향의 ecnt를 갱신하고 내려갈 수 있음
            solve(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;
    tot_w = 0; tot_b = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
        if (C[i] == 0) tot_w++;
        else tot_b++;
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_init(1, 0);
    solve(1, 0);

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }

    return 0;
}