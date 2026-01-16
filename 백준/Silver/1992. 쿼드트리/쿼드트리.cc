#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char p[65][65];

string f(int x, int y, int size){
	char t = p[x][y];
	for(int i = x; i < x+size; i++){
		for(int j = y; j < y+size; j++){
			if(p[i][j] != t){
				int h = size / 2;
				return "("+f(x, y, h)+f(x, y+h, h)+f(x+h, y, h)+f(x+h, y+h, h)+")";
			}
		}
	}
	return string(1, t);
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> p[i][j];
	}
	cout << f(0, 0, n);
    return 0;
}