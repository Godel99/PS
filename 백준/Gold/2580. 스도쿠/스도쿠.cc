#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int FULL = 1022;

int board[9][9];
int rowc[9], colc[9], boxc[9];

inline int get_num(int bit) {
    return __builtin_ctz(bit);
}

void update(int r, int c, int n, bool s) {
    int bit = 1 << n;
    int b = (r / 3) * 3 + (c / 3);
    if(s){
        board[r][c] = n;
        rowc[r] |= bit; colc[c] |= bit; boxc[b] |= bit;
    }else{
        board[r][c] = 0;
        rowc[r] ^= bit; colc[c] ^= bit; boxc[b] ^= bit;
    }
}

inline int avail(int r, int c){
    return ~(rowc[r] | colc[c] | boxc[(r / 3) * 3 + (c / 3)]) & FULL;
}

void propa() {
    while (true) {
        bool flag = false;
        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] == 0){
                    int ava = avail(r, c);
                    if(ava && (ava & (ava - 1)) == 0){
                        update(r, c, get_num(ava), true);
                        flag = true;
                    }
                }
            }
        }
        for(int r = 0; r < 9; ++r){
            int arow = FULL & ~rowc[r];
            while(arow){
                int bit = arow & -arow;
                int num = get_num(bit);
                int nc = -1, cnt = 0;
                for(int c = 0; c < 9; ++c){
                    if(board[r][c] == 0 && !(colc[c] & bit || boxc[(r/3)*3+(c/3)] & bit)){
                        cnt++; nc = c;
                        if (cnt > 1) break;
                    }
                }
                if(cnt == 1){ update(r, nc, num, true); flag = true; }
                arow &= ~bit;
            }
        }
        for(int b = 0; b < 9; b++){
            int abox = FULL&~boxc[b];
            while(abox){
                int bit = abox & -abox;
                int num = get_num(bit);
                int nr = -1, nc = -1, cnt = 0;
                for(int i = 0; i < 9; i++){
                    int r = (b/3)*3+(i/3);
                    int c = (b%3)*3+(i%3);
                    if(board[r][c] == 0) if(not (rowc[r]&bit || colc[c]&bit)){
                        cnt++;
                        nr = r, nc = c;
                        if(cnt > 1) break;
                    }
                }
                if(cnt == 1){ update(nr, nc, num, 1); flag = true; }
                abox &= ~bit;
            }
        }
        if(!flag) break;
    }
}

vector<pii> blank;
void dfs(int idx) {
    if(idx == blank.size()){
        for(int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) cout << board[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    int r = blank[idx].first, c = blank[idx].second;
    int ava = avail(r, c);
    while(ava){
        int bit = ava & -ava;
        update(r, c, get_num(bit), true);
        dfs(idx + 1);
        update(r, c, get_num(bit), false);
        ava &= ~bit;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            int n; cin >> n;
            if(n) update(i, j, n, true);
        }
    }
    propa();
    for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j){
        if(board[i][j] == 0) blank.push_back({i, j});
    }
    dfs(0);
    return 0;
}