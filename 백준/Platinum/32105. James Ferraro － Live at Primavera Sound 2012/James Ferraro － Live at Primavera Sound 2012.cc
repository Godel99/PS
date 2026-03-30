#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    bool isp[N+1]; memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    for(int i = 4; i <= N; i += 2) isp[i] = 0;
    for(int i = 3; i*i <= N+1; i++){
        if(isp[i]) for(int j = i*i; j <= N+1; j+=i) isp[j] = 0;
    }
    vector<pll> ans; ans.reserve(N/2);
    while(N > 7){
        int r = ((3-N)%6+6)%6;
        int s = (N-1)-((N-1-r)%6+6)%6;
        for(int L = s; L > 0; L -=6) if(isp[(L+N)/3]){
            for(int i = 0; i < (N-L+1)/2; i++) ans.push_back({L+i, N-i});
            N = L-1;
            break;
        }
    
    }
    if(N >= 6) ans.insert(ans.end(), { {1, 5}, {2, 4}, {3, 6} });
    else if(N >= 4) ans.insert(ans.end(), { {1, 3}, {2, 4} });
    else if(N == 3) ans.push_back({1, 3});
    cout << ans.size() << '\n';
    for(auto& [x, y] : ans) cout << x << ' ' << y << '\n';
    return 0;
}