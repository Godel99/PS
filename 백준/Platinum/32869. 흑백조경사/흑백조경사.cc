#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int N;
int C[MAXN];
vector<int> adj[MAXN];

int sub_w[MAXN], sub_b[MAXN];
int W_total = 0, B_total = 0;
int bad_count[MAXN];

// 자손들의 색상 분포와 현재 노드의 색상을 비교하여 Even 조건을 만족하는지 확인
bool check_valid(int w_desc, int b_desc, int color) {
    if (w_desc > b_desc && color != 0) return false;
    if (b_desc > w_desc && color != 1) return false;
    return true;
}

// 부모 u에서 자식 v로 가는 방향일 때, v가 Even 조건을 만족하는지 확인
bool valid_edge(int w_comp, int b_comp, int c_v) {
    int w_desc = w_comp - (c_v == 0 ? 1 : 0);
    int b_desc = b_comp - (c_v == 1 ? 1 : 0);
    return check_valid(w_desc, b_desc, c_v);
}

// DFS 1: 각 서브트리의 흰색/검은색 노드 개수를 센다.
void dfs1(int u, int p) {
    sub_w[u] = (C[u] == 0 ? 1 : 0);
    sub_b[u] = (C[u] == 1 ? 1 : 0);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub_w[u] += sub_w[v];
        sub_b[u] += sub_b[v];
    }
}

// DFS 2: 1번 노드를 루트로 했을 때의 위반 간선(bad_count) 초기값을 구한다.
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!valid_edge(sub_w[v], sub_b[v], C[v])) {
            bad_count[1]++;
        }
        dfs2(v, u);
    }
}

// DFS 3: Re-rooting 기법을 통해 모든 노드에 대한 bad_count를 O(1)에 갱신한다.
void dfs3(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        
        bad_count[v] = bad_count[u];
        
        // 1. 기존의 u -> v 방향 간선이 시야에서 사라짐
        if (!valid_edge(sub_w[v], sub_b[v], C[v])) {
            bad_count[v]--;
        }
        
        // 2. 새로운 v -> u 방향 간선이 시야에 들어옴
        // v가 루트일 때 u가 포함된 컴포넌트의 색상 수 계산
        int w_vu = W_total - sub_w[v];
        int b_vu = B_total - sub_b[v];
        if (!valid_edge(w_vu, b_vu, C[u])) {
            bad_count[v]++;
        }
        
        dfs3(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
        if (C[i] == 0) W_total++;
        else B_total++;
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);

    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        // 간선 위반이 없고, 해당 노드 자체도 루트로서 Even 조건을 만족하는지 판별
        if (bad_count[i] == 0) {
            int root_w_desc = W_total - (C[i] == 0 ? 1 : 0);
            int root_b_desc = B_total - (C[i] == 1 ? 1 : 0);
            if (check_valid(root_w_desc, root_b_desc, C[i])) {
                ans.push_back(i);
            }
        }
    }

    // 결과 출력
    cout << ans.size() << "\n";
    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}