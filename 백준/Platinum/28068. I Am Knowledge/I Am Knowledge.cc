#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> pb, mb;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a <= b) pb.push_back({a, b});
        else mb.push_back({b, a});
    }
    sort(pb.begin(), pb.end());
    sort(mb.begin(), mb.end(), greater<pii>());
    ll joy = 0;
    for(auto [a, b] : pb){
        if(a > joy) return !(cout << 0);
        joy += b-a;
    }
    for(auto [b, a] : mb){
        if(a > joy) return !(cout << 0);
        joy -= a-b;
    }
    cout << 1;
    return 0;
}