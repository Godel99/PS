import sys

def solve():
    # 1. Fast I/O: 전체 입력을 한 번에 읽어와서 공백 기준으로 분리
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    h = [int(x) for x in input_data[1:]]
    MOD = 1000000007
    
    # 2. 동적 할당(append/pop) 오버헤드를 없애기 위한 크기 고정 배열과 포인터
    C = [1] * N
    S = [0] * N
    sp = 0
    
    ret = 0
    
    # 3. 핵심 로직 (지역 변수 환경에서 실행되어 조회 속도가 극대화됨)
    for i in range(N):
        hi = h[i]
        
        while sp > 0 and h[S[sp - 1]] <= hi:
            sp -= 1
            j = S[sp]
            
            # 왼쪽 벽과 오른쪽 벽 중 더 낮은 벽(k)을 찾음
            if sp > 0 and h[S[sp - 1]] < hi:
                k = S[sp - 1]
            else:
                k = i
                
            diff = h[k] - h[j]
            # 비용 계산: 파이썬은 정수 오버플로우가 없지만, 
            # 숫자가 너무 커지면 연산 속도가 미세하게 느려지므로 적절히 MOD 처리
            ways = (N - C[j]) * C[j] % MOD
            cost = diff * diff % MOD
            
            ret = (ret + ways * cost) % MOD
            C[k] += C[j]
            
        S[sp] = i
        sp += 1
        
    # 4. 스택에 남은 원소들 (오른쪽 벽을 찾지 못한 건물들) 처리
    while sp > 1:
        i_idx = S[sp - 1]
        j_idx = S[sp - 2]
        
        diff = h[j_idx] - h[i_idx]
        ways = (N - C[i_idx]) * C[i_idx] % MOD
        cost = diff * diff % MOD
        
        ret = (ret + ways * cost) % MOD
        C[j_idx] += C[i_idx]
        sp -= 1
        
    print(ret)

# 함수 호출로 실행 (전역 공간 실행보다 바이트코드 최적화가 잘 됨)
if __name__ == '__main__':
    solve()