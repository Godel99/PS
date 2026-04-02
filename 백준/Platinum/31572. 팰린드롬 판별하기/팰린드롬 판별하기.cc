#include<bits/stdc++.h>
using namespace std;

extern int count_pair(int, int, int);
extern int find_character(int, vector<int>);

int guess_palindromicity(int n){
    vector<int> one;
    int thr = -1;
    for(int i = 0; i < (n-1)/2; i++){
        int qry = count_pair(i, (n-1)/2, n-1-i);
        if(qry == 0) return 0;
        if(qry == 1){
            one.push_back(i);
            one.push_back(n-1-i);
        }
        else thr = i;
    }
    if(~n&1){
        if(thr < 0){
            int qry = count_pair(0, (n-1)/2, (n+1)/2);
            if(qry != 1) return 0;
            qry = count_pair(0, (n+1)/2, n-1);
            if(qry != 1) return 0;
        }
        else{
            int qry = count_pair((n-1)/2, (n+1)/2, thr);
            if(qry != 3) return 0;
        }
    }
    return (one.empty() || !find_character((n-1)/2, one));
}