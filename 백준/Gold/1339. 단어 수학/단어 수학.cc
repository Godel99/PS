#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i< n; i++) cin >> words[i];
    unordered_map<char, ll> weight;
    for(const string& word : words){
        ll p = 1;
        for(int i = word.length()-1; i >= 0; i--){
            weight[word[i]] += p;
            p *= 10;
        }
    }
    vector<ll> vals;
    for(auto &v: weight) vals.push_back(v.second);
    sort(vals.begin(), vals.end(), greater<>());
    int num = 9; ll ans = 0;
    for(ll val : vals){
        ans += num*val;
        num--;
    }
    cout << ans;
    return 0;
}