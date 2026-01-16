#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void hanoi(int d, int start, int via, int end){
	if(d == 1){
		cout << start << ' ' << end << '\n';
		return;
	}
	hanoi(d-1, start, end, via);
	cout << start << ' ' << end << '\n';
	hanoi(d-1, via, start, end);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	cout << (1<<n)-1 << '\n';
	hanoi(n, 1, 2, 3);
    return 0;
}