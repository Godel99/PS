#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
    vector<int> ans(n+1, -1);
	while(m--){
		int k; cin >> k;
		vector<int> clause(k);
        for(int i = 0; i < k; i++) cin >> clause[i];
		bool flag = 1;
        for(int i = 0; i < k; i++){
            int x = abs(clause[i]);
            bool req = clause[i] < 0 ? 1 : 0;
            if(ans[x] == -1) ans[x] = req;
            else if(ans[x] != req){
                flag = 0; break;
            }
        }
        if(flag){
            cout << "YES" << '\n';
            for(int i = 1; i <= n; i++) cout << (ans[i] == -1 ? 0 : ans[i]) << ' ';
            return 0;
        }
        for(int i = 0; i < k; i++) ans[abs(clause[i])] = -1;
    }
    cout << "NO";
    return 0;
}