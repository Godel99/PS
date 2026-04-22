#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> ans(n, 0), cnt(n+1, 0), head(n+1, -1), nxt(n+1, -1), pre(n+1, -1);
    vector<bool> vis(n, 0);
    int mcnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    function<void(int, int)> Add = [&](int c, int x){
        nxt[x] = head[c];
        if(head[c] != -1) pre[head[c]] = x;
        head[c] = x;
    };
    function<void(int, int)> Remove = [&](int c, int x){
        if(pre[x] != -1) nxt[pre[x]] = nxt[x];
        else head[c] = nxt[x];
        if(nxt[x] != -1) pre[nxt[x]] = pre[x];
        pre[x] = nxt[x] = -1;
        cnt[x]--;
        Add(cnt[x], x);
        if(head[mcnt] == -1) mcnt--;
    };
    for(int i = 1; i <= n; i++) if(cnt[i]){
        Add(cnt[i], i);
        if(mcnt < cnt[i]) mcnt = cnt[i];
    }
    if(2*mcnt-1 > n) return !(cout << -1);
    int idx = 0, size = n, p1 = 0, p2 = 1;
    while(p2 < n && a[p2-1] == a[p2]) p2++;
    while(idx < n && 2*mcnt-1 < size){
        while(a[p1] == a[p2] || vis[p1]) p1++;
        vis[p1] = 1;
        size--;
        Remove(cnt[a[p1]], a[p1]);
        ans[idx++] = p1+1;
        if(idx == n || 2*mcnt-1 == size) break;
        while(a[p1] == a[p2] or vis[p2]) p2++;
        vis[p2] = 1;
        size--;
        Remove(cnt[a[p2]], a[p2]);
        ans[idx++] = p2+1;
    }
    int maxv = head[mcnt];
    p1 = 0;
    while(vis[p1]) p1++;
    p2 = p1;
    while(idx < n){
        while(a[p1] != maxv || vis[p1]) p1++;
        vis[p1] = 1;
        ans[idx++] = p1+1;
        if(idx == n) break;
        while(a[p2] == maxv || vis[p2]) p2++;
        vis[p2] = 1;
        ans[idx++] = p2+1;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    return 0;
}