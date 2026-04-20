import sys
from math import gcd

def solve():
    # 1. 입력 속도 최적화: 전체 데이터를 한 번에 읽어와 쪼갭니다.
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    M = int(input_data[1])
    
    ptr = 2
    queries = []
    # z별 차분 배열 (1~16)
    diff = [[0] * (N + 2) for _ in range(17)]
    
    for _ in range(M):
        x = int(input_data[ptr])
        y = int(input_data[ptr+1])
        z = int(input_data[ptr+2])
        ptr += 3
        queries.append((x, y, z))
        # 차분 배열에 마킹
        diff[z][x] += 1
        diff[z][y + 1] -= 1

    # 2. D[i] (ans) 계산: 1부터 16까지 루프 돌며 LCM 적용
    ans = [1] * N
    for z in range(1, 17):
        cnt = 0
        dz = diff[z]
        for i in range(1, N + 1):
            cnt += dz[i]
            if cnt > 0:
                # ans[i-1] = lcm(ans[i-1], z)
                curr = ans[i-1]
                ans[i-1] = (curr * z) // gcd(curr, z)

    # 3. Sparse Table 구성 (O(N log N))
    # Python에서 2차원 리스트 접근은 st[j][i] 형태가 빠릅니다.
    st = [ans]
    
    # N의 길이에 따른 최대 로그 값 계산
    max_log = N.bit_length()
    for j in range(1, max_log):
        prev = st[j-1]
        offset = 1 << (j - 1)
        # 현재 레벨에서 계산 가능한 구간까지만 gcd 계산
        curr = [0] * (N - (1 << j) + 1)
        for i in range(N - (1 << j) + 1):
            curr[i] = gcd(prev[i], prev[i + offset])
        st.append(curr)

    # 4. 검증 (O(1) 쿼리)
    results = []
    for l, r, z in queries:
        # 0-based 인덱스로 변환
        l_idx, r_idx = l - 1, r - 1
        length = r_idx - l_idx + 1
        # k = floor(log2(length))
        k = length.bit_length() - 1
        
        # Sparse Table을 이용한 O(1) GCD 조회
        res = gcd(st[k][l_idx], st[k][r_idx - (1 << k) + 1])
        
        if res != z:
            sys.stdout.write("Impossible\n")
            return

    # 5. 결과 출력 최적화
    sys.stdout.write(" ".join(map(str, ans)) + "\n")

if __name__ == "__main__":
    solve()