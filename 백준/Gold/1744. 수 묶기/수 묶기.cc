#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> pos, neg;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x <= 0) neg.push_back(x);
        else if(x > 1) pos.push_back(x);
        else ans++;
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end()); 
    for(int i = 0; i < pos.size(); i += 2){
        if(i + 1 < pos.size()) ans += pos[i]*pos[i+1];
        else ans += pos[i];
    }
    for(int i = 0; i < neg.size(); i += 2){
        if(i + 1 < neg.size()) ans += neg[i]*neg[i+1];
        else ans += neg[i];
    }
    cout << ans;
    return 0;
}