#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pcc = pair<char, char>;

unordered_map<char, pcc> tree;

void preorder(char node){
    if(node == '.') return;
    cout << node;
    preorder(tree[node].first);
    preorder(tree[node].second);
}

void inorder(char node){
    if(node == '.') return;
    inorder(tree[node].first);
    cout << node;
    inorder(tree[node].second);
}
void postorder(char node){
    if(node == '.') return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    cout << node;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c; cin >> a >> b >> c;
        tree[a] = {b, c};
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
    return 0;
}