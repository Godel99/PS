#include <iostream>

using namespace std;

int N;
int r_pos[10005]; // 등급별 행 위치
int c_pos[10005]; // 등급별 열 위치
int match[10005]; // 각 칸과 매칭된 칸 번호
int visited[10005]; 
bool active[10005]; // 해당 칸의 활성화 여부
int timer = 0; // O(1) 방문 초기화를 위한 타임스탬프

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 대칭적 증가 경로 탐색 (Symmetric DFS)
bool dfs(int u) {
    int r = u / N;
    int c = u % N;
    
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        // 격자 범위를 벗어난 경우 무시
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        
        int v = nr * N + nc;
        
        // 인접한 칸이 아직 비활성화 상태이거나, 이번 턴에 이미 방문했다면 무시
        if (!active[v] || visited[v] == timer) continue;
        visited[v] = timer;
        
        // 인접한 칸이 매칭되지 않았거나, 기존 매칭된 칸이 다른 곳과 매칭 가능하다면
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    int limit = N * N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k;
            cin >> k;
            r_pos[k] = i; // 값 k가 있는 좌표 캐싱
            c_pos[k] = j;
        }
    }

    // 매칭 배열 초기화 (-1은 매칭 안 됨을 의미)
    for (int i = 0; i < limit; ++i) {
        match[i] = -1;
    }

    int match_cnt = 0;
    int target = limit / 2; // 최대 도미노 개수

    // 1부터 N^2까지 순차적으로 활성화
    for (int k = 1; k <= limit; ++k) {
        int u = r_pos[k] * N + c_pos[k];
        active[u] = true;
        
        timer++; // memset을 대체하는 타임스탬프 증가 (O(1))
        
        // 새롭게 활성화된 칸에서만 DFS 시작
        if (dfs(u)) {
            match_cnt++;
            cout << k << '\n'; // 매칭이 증가하는 순간의 등급 출력
            
            // 필요한 매칭(N^2 / 2)을 모두 찾았다면 조기 종료
            if (match_cnt == target) break;
        }
    }

    return 0;
}