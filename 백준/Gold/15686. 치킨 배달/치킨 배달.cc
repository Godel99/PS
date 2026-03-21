#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pii> house, chicken;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        int x; cin >> x;
        if(x == 1) house.push_back({i, j});
        else if(x == 2) chicken.push_back({i, j});
    }
    int h_cnt = house.size(), c_cnt = chicken.size();
    vector<vector<int>> dist(h_cnt, vector<int>(c_cnt));
    for(int i = 0; i < h_cnt; i++) for(int j = 0; j < c_cnt; j++){
        dist[i][j] = abs(house[i].first-chicken[j].first)+abs(house[i].second-chicken[j].second);
    }
    vector<int> mask(c_cnt, 1);
    fill(mask.begin(), mask.begin()+m, 0);
    int mindist = INF;
    do{
        int curdist = 0;
        for(int i = 0; i < h_cnt; i++){
            int minhdist = INF;
            for(int j = 0; j < c_cnt; j++){
                if(!mask[j]) minhdist = min(minhdist, dist[i][j]);
            }
            curdist += minhdist;
            if(curdist >= mindist) break;
        }
        mindist = min(mindist, curdist);
    }while(next_permutation(mask.begin(), mask.end()));
    cout << mindist;
    return 0;
} 