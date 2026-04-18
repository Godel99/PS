#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
// N <= 200,000 이고 각 노드당 log N 개의 세그먼트 트리 노드가 생기므로 넉넉하게 잡습니다.
const int MAX_NODES = 5000005; 

struct SegNode {
    int lc, rc;
    int val;
} tr[MAX_NODES];

int node_cnt = 0;
int rt[MAXN];
vector<int> adj[MAXN];
int val[MAXN];
int ans[MAXN];
int N;

// 세그먼트 트리에 값을 업데이트 (초기화용)
void update(int& node, int l, int r, int x) {
    if (!node) node = ++node_cnt;
    if (l == r) {
        tr[node].val = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    if (x <= mid) update(tr[node].lc, l, mid, x);
    else update(tr[node].rc, mid + 1, r, x);
    
    tr[node].val = tr[tr[node].lc].val + tr[tr[node].rc].val;
}

// 두 세그먼트 트리를 파괴적으로 병합 (부모 노드에 자식 노드를 흡수)
int merge(int u, int v, int l, int r) {
    if (!u || !v) return u ? u : v;
    if (l == r) {
        tr[u].val = 1; // 둘 중 하나라도 존재하면 1
        return u;
    }
    int mid = l + (r - l) / 2;
    tr[u].lc = merge(tr[u].lc, tr[v].lc, l, mid);
    tr[u].rc = merge(tr[u].rc, tr[v].rc, mid + 1, r);
    
    tr[u].val = tr[tr[u].lc].val + tr[tr[u].rc].val;
    return u;
}

// 세그먼트 트리에서 MEX(가장 작은 빈 값) 찾기
int get_mex(int node, int l, int r) {
    // 해당 구간을 관리하는 노드가 없으면 첫 번째 값인 l이 MEX
    if (!node) return l; 
    
    // 리프 노드까지 도달했는데 노드가 존재한다는 것은 
    // 값이 존재한다는 뜻이므로, 그 다음 값이 MEX가 됨
    if (l == r) return l + 1; 
    
    int mid = l + (r - l) / 2;
    int left_full = mid - l + 1;
    
    // 왼쪽 구간이 꽉 차있으면 오른쪽에서 탐색, 아니면 왼쪽에서 탐색
    if (tr[tr[node].lc].val == left_full) {
        return get_mex(tr[node].rc, mid + 1, r);
    } else {
        return get_mex(tr[node].lc, l, mid);
    }
}

// DFS를 통한 트리 순회 및 연산
void dfs(int u) {
    // 현재 노드의 값을 세그먼트 트리에 추가
    update(rt[u], 0, N, val[u]); 
    
    for (int v : adj[u]) {
        dfs(v);
        // 자식 트리의 결과를 현재 노드의 트리에 병합
        rt[u] = merge(rt[u], rt[v], 0, N); 
    }
    
    // 모든 자식을 병합한 후 현재 서브트리의 MEX 계산
    ans[u] = get_mex(rt[u], 0, N);
}

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    int root = -1;
    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        if (p == -1) {
            root = i; // 부모가 -1이면 트리의 루트
        } else {
            adj[p].push_back(i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cin >> val[i];
    }

    dfs(root);

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}