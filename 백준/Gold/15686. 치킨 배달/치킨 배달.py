import sys
# 효율적인 출력을 위한 설정
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    hou, chi = [], []
    
    for r in range(n):
        row = list(map(int, input().split()))
        for c in range(n):
            if row[c] == 1: hou.append((r, c))
            elif row[c] == 2: chi.append((r, c))
            
    houl, chil = len(hou), len(chi)
    # 거리 행렬 미리 계산
    dist = [[abs(hr-cr)+abs(hc-cc) for cr, cc in chi] for hr, hc in hou]
    
    ans = float('inf')
    selected_chi = []

    def dfs(idx, cnt):
        nonlocal ans
        
        # 1. 종료 조건: m개를 모두 선택했을 때
        if cnt == m:
            cur_city_dist = 0
            for h_i in range(houl):
                min_h_dist = float('inf')
                # 선택된 치킨집 인덱스들(selected_chi) 중에서 최솟값 찾기
                for c_i in selected_chi:
                    if dist[h_i][c_i] < min_h_dist:
                        min_h_dist = dist[h_i][c_i]
                
                cur_city_dist += min_h_dist
                if cur_city_dist >= ans: break # 가지치기
            else:
                ans = min(ans, cur_city_dist)
            return

        # 2. 남은 치킨집을 다 합쳐도 m개를 채울 수 없는 경우 (최적화)
        if idx == chil:
            return

        # 3. 현재 치킨집(idx)을 선택함
        selected_chi.append(idx)
        dfs(idx + 1, cnt + 1)
        selected_chi.pop() # 백트래킹의 핵심: 원상복구

        # 4. 현재 치킨집(idx)을 선택하지 않음
        dfs(idx + 1, cnt)

    dfs(0, 0)
    print(ans)

if __name__ == '__main__':
    solve()