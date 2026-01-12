#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    cout << "<";
    while(!q.empty()){
        for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">";
    return 0;
}