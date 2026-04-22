#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 세그먼트 트리 노드
struct Node {
    int min1;
    int type1;
    int min2;
};

int N;
vector<int> A;
vector<Node> tree;

// 두 노드를 병합하여 최소 인덱스와, 그와 종류가 다른 최소 인덱스를 계산
Node merge_nodes(const Node& a, const Node& b) {
    Node res;
    if (a.min1 < b.min1) {
        res.min1 = a.min1;
        res.type1 = a.type1;
        int c1 = a.min2;
        int c2 = (b.type1 != res.type1) ? b.min1 : b.min2;
        res.min2 = min(c1, c2);
    } else {
        res.min1 = b.min1;
        res.type1 = b.type1;
        int c1 = b.min2;
        int c2 = (a.type1 != res.type1) ? a.min1 : a.min2;
        res.min2 = min(c1, c2);
    }
    return res;
}

// 세그먼트 트리 초기화
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = {l, A[l], INF};
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = merge_nodes(tree[node * 2], tree[node * 2 + 1]);
}

// 특정 인덱스를 사용 처리 (INF로 변경)
void update(int node, int l, int r, int idx) {
    if (l == r) {
        tree[node] = {INF, 0, INF};
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx);
    else update(node * 2 + 1, mid + 1, r, idx);
    tree[node] = merge_nodes(tree[node * 2], tree[node * 2 + 1]);
}

// O(1) 빈도수 추적을 위한 배열 기반 이중 연결 리스트
int cnt[300005];
int head[300005], nxt[300005], prv[300005];
int max_c = 0;

void add_list(int x, int c) {
    nxt[x] = head[c];
    if (head[c] != -1) prv[head[c]] = x;
    head[c] = x;
    prv[x] = -1;
    if (c > max_c) max_c = c;
}

void remove_list(int x, int c) {
    if (prv[x] != -1) nxt[prv[x]] = nxt[x];
    else head[c] = nxt[x];
    if (nxt[x] != -1) prv[nxt[x]] = prv[x];
    
    // 최대 빈도수 포인터 하향 조정 (Amortized O(1))
    while (max_c > 0 && head[max_c] == -1) max_c--;
}

void decrease_cnt(int x) {
    int c = cnt[x];
    remove_list(x, c);
    cnt[x]--;
    if (cnt[x] > 0) add_list(x, cnt[x]);
}

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    A.resize(N + 1);
    vector<vector<int>> pos(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    // 리스트 초기화
    for (int i = 0; i <= N; i++) {
        head[i] = -1;
        nxt[i] = prv[i] = -1;
    }

    // 초기 빈도수 등록
    for (int i = 1; i <= N; i++) {
        if (cnt[i] > 0) add_list(i, cnt[i]);
    }

    // 처음부터 올바른 식사 계획이 불가능한 경우 (가장 많은 음식이 절반 초과)
    if (max_c * 2 > N + 1) {
        cout << -1 << "\n";
        return 0;
    }

    // 특정 음식의 인덱스들을 역순으로 저장하여 pop_back()으로 O(1)에 최소 인덱스 조회
    for (int i = N; i >= 1; i--) {
        pos[A[i]].push_back(i);
    }

    tree.resize(4 * N + 1);
    build(1, 1, N);

    vector<int> ans;
    int last = -1;

    // N번의 방문 계획 수립
    for (int R = N; R >= 1; R--) {
        int pick_idx = -1;
        
        // 1. 강제 선택이 필요한 상황
        if (max_c * 2 == R + 1) {
            int forced_type = head[max_c];
            // 강제 선택해야 하는 음식이 직전 음식과 동일하면 실패
            if (forced_type == last) {
                cout << -1 << "\n";
                return 0;
            }
            pick_idx = pos[forced_type].back();
        } 
        // 2. 여유가 있는 상황
        else {
            if (tree[1].type1 != last) {
                pick_idx = tree[1].min1;
            } else {
                pick_idx = tree[1].min2;
            }
        }

        // 선택 가능한 유효한 식당이 없으면 불가능 처리
        if (pick_idx == INF || pick_idx == -1) {
            cout << -1 << "\n";
            return 0;
        }

        ans.push_back(pick_idx);
        last = A[pick_idx];
        
        // 상태 갱신
        decrease_cnt(last);
        update(1, 1, N, pick_idx);
        pos[last].pop_back();
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}