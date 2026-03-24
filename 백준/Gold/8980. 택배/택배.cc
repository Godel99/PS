#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using aiii = array<int, 3>;

struct SegTree {
    int n;
    vector<int> tree, lazy;
    SegTree(int n) : n(n) {
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void push(int node) {
        if (lazy[node] != 0) {
            for (int nxt : {node*2, node*2+1}) {
                tree[nxt] += lazy[node];
                lazy[nxt] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_add(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        range_add(node*2, l, mid, ql, qr, val);
        range_add(node*2+1, mid+1, r, ql, qr, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    int query_max(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node);
        int mid = (l + r) / 2;
        return max(
            query_max(node*2, l, mid, ql, qr),
            query_max(node*2+1, mid+1, r, ql, qr)
        );
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, c, m; cin >> n >> c >> m;
    vector<aiii> d(m);
    for(int i = 0; i < m; i++) cin >> d[i][0] >> d[i][1] >> d[i][2];
    sort(d.begin(), d.end(), [](const aiii& a, const aiii& b){
        return a[1] < b[1];
    });
    SegTree seg(n);
    int ans = 0;
    for(auto &[s, e, w]: d){
        int mx = seg.query_max(1, 1, n, s, e-1);
        int can = min(w, c-mx);
        seg.range_add(1, 1, n, s, e-1, can);
        ans += can;
    }
    cout << ans;
    return 0;
}