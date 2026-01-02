#include<bits/stdc++.h>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using ll=long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    while (true){
        vector<int> tri(3);
        for (int i = 0; i < 3; i++) cin >> tri[i];
        if (tri == vector({0,0,0})) break;
        sort(tri.begin(), tri.end());
        if (pow(tri[2],2) == (pow(tri[0],2) + pow(tri[1],2))) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
}