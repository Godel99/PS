#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    const int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
    const char dlru[] = {'d', 'l', 'r', 'u'};
    int dist = abs(x-r)+abs(y-c);
    if(dist > k || (dist-k)&1) return "impossible";
    bool flag = 0;
    string ans = "";
    function<void(int, int, int, string)> dfs = [&](int cx, int cy, int d, string path){
        if(flag) return;
        int dist = abs(cx-r)+abs(cy-c);
        if(dist > k-d || (k-d-dist)&1) return;
        if(d == k){
            if(cx == r and cy == c){
                ans = path;
                flag = 1;
            }
            return;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = cx+dx[dir], ny = cy+dy[dir];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m) dfs(nx, ny, d+1, path+dlru[dir]);
        }
    };
    dfs(x, y, 0, "");
    return ans;
}