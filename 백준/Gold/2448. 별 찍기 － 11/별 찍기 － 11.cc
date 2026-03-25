#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> tree_star(int n){
    if(n == 3) return {"  *  ", " * * ", "*****"};
    vector<string> star = tree_star(n/2);
    vector<string> ret;
    string space(n/2, ' ');
    for(const string& s: star) ret.push_back(space+s+space);
    for(const string& s: star) ret.push_back(s+" "+s);
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    for(const string& r: tree_star(n)) cout << r << '\n';
    return 0;
} 