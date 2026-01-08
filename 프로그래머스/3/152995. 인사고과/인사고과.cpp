#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<vector<int>> scores) {
    vector<int> wanho = scores[0];
    int wanho_sum = wanho[0] + wanho[1];
    sort(scores.begin(), scores.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
        });
    int maxs = -1; 
    int rank = 1;
    for(auto s : scores){
        if(s[1] < maxs){
            if(s[0] == wanho[0] && s[1] == wanho[1]) return -1;
            continue;
        }
        maxs = s[1];
        if(s[0] + s[1] > wanho_sum) rank++;
    }
    return rank;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cout << solution({{2,2}, {1,4}, {3,2}, {3,2}, {2,1}});
}