#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, maxv = 0; cin >> n;
    vector<int> card(n), score(n, 0), loc(1'000'000, -1);
    for(int i = 0; i < n; i++){
        cin >> card[i];
        loc[card[i]] = i;
        if(maxv < card[i]) maxv = card[i];
    }
    for(int i = 0; i < n; i++){
        int cur = card[i];
        for(int j = cur*2; j <= maxv; j += cur) if(loc[j] != -1){
            score[i]++;
            score[loc[j]]--;
        }
    }
    for(int i = 0; i < n; i++) cout << score[i] << ' ';
    return 0;
}