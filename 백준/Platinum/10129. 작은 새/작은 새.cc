#include<bits/stdc++.h>
using namespace std;

struct st{
    int idx, val, h;
};

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int q; cin >> q;

    while (q--){
        deque<st> dp;
        int k; cin >> k;

        dp.push_back({0,0,h[0]});

        for (int i = 1; i < n; i++){
            while (dp.size() && dp.front().idx + k < i) dp.pop_front();
            int now = dp.front().val + (bool)(dp.front().h <= h[i]);
            while (dp.size() && (dp.back().val > now || dp.back().val == now && dp.back().h <= h[i])) dp.pop_back();
            dp.push_back({i, now, h[i]});
        }
        cout << dp.back().val << '\n';
    }
}
