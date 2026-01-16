#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int p[129][129];

pii f(int x, int y, int size){
	int t = p[x][y];
	for(int i = x; i < x+size; i++){
		for(int j = y; j < y+size; j++){
			if(p[i][j] != t){
				int h = size / 2;
				auto[w1, b1] = f(x, y, h);
				auto[w2, b2] = f(x, y+h, h);
				auto[w3, b3] = f(x+h, y, h);
				auto[w4, b4] = f(x+h, y+h, h);
				return {w1+w2+w3+w4, b1+b2+b3+b4};
			}
		}
	}
	if(t) return {0, 1};
	else return {1, 0};
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> p[i][j];
	}
	auto[w, b] = f(0, 0, n);
	cout << w << '\n' << b;
    return 0;
}