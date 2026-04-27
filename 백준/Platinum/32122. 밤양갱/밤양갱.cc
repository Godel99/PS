#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수 설정 (N=100 기준 넉넉하게 할당)
int N;
int A[105][105];
pair<int, int> P[10005];
int MATCH[10005];
int VIS[10005];
int PTR[10005];

// 이동 방향
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// 2차원 좌표를 1차원 인덱스로 변환
inline int lab(int x, int y) { return x * N + y; }

bool dfs(int i) {
    int sx = P[i].first;
    int sy = P[i].second;
    int start_l = lab(sx, sy);

    // 이미 매칭된 노드라면 건너뜀 (이분 매칭의 효율성)
    if (MATCH[start_l] != -1) return false;

    VIS[start_l] = i;
    PTR[start_l] = 0;
    
    // 비재귀 DFS를 위한 스택 (PATH)
    vector<pair<int, int>> PATH;
    PATH.push_back({sx, sy});

    while (!PATH.empty()) {
        pair<int, int> curr = PATH.back();
        int x = curr.first;
        int y = curr.second;
        int l = lab(x, y);

        if (PTR[l] == 4) { // 4방향을 모두 확인한 경우
            if (PATH.size() == 1) break;
            // 스택에서 현재 노드와 그 파트너를 제거 (백트래킹)
            PATH.pop_back(); 
            PATH.pop_back();
        } else {
            int nx = x + dx[PTR[l]];
            int ny = y + dy[PTR[l]];
            PTR[l]++;

            // 격자 범위 밖이거나, 이미 방문했거나, 아직 활성화되지 않은 칸(등급 > i)은 무시
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int nl = lab(nx, ny);
            if (VIS[nl] == i || A[nx][ny] > i) continue;

            if (MATCH[nl] == -1) { // 매칭되지 않은 인접 칸을 찾은 경우 (증가 경로 발견!)
                PATH.pop_back();
                MATCH[l] = nl;
                MATCH[nl] = l;
                
                // 스택을 거꾸로 올라가며 매칭 정보 업데이트
                while (!PATH.empty()) {
                    pair<int, int> p1 = PATH.back(); PATH.pop_back();
                    pair<int, int> p2 = PATH.back(); PATH.pop_back();
                    int l1 = lab(p1.first, p1.second);
                    int l2 = lab(p2.first, p2.second);
                    MATCH[l1] = l2;
                    MATCH[l2] = l1;
                }
                return true;
            }

            // 이미 매칭된 칸이라면, 그 칸의 파트너로 이동하여 탐색 계속
            VIS[nl] = i;
            PATH.push_back({nx, ny});
            
            int partner_l = MATCH[nl];
            int px = partner_l / N;
            int py = partner_l % N;
            
            PATH.push_back({px, py});
            PTR[partner_l] = 0; // 새롭게 경로에 추가된 노드의 포인터 초기화
        }
    }
    return false;
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    // 격자판 정보 입력 및 위치 매핑
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            P[A[i][j]] = {i, j};
        }
    }

    // MATCH 배열 초기화
    fill(MATCH, MATCH + (N * N), -1);
    fill(VIS, VIS + (N * N), 0);

    // 등급 1부터 N*N까지 하나씩 추가하며 매칭 시도
    for (int i = 1; i <= N * N; i++) {
        if (dfs(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}