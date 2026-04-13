import sys

# FIO 대신 깔끔한 내장 I/O 사용
input = sys.stdin.readline
MOD = 998244353

def solve():
    n, m, k_val = map(int, input().split())
    indeg = [0] * (n + 1)
    for _ in range(m):
        _, v = map(int, input().split())
        indeg[v] += 1

    # 정점들의 차수별 개수 카운트 (불필요한 중복 연산 방지)
    vcnt = {}
    for i in range(2, n + 1):
        if indeg[i] > 0:
            vcnt[indeg[i]] = vcnt.get(indeg[i], 0) + 1

    if not vcnt:
        print(0)
        return

    MAX_D = max(vcnt.keys())

    # 1. 팩토리얼 및 역원 전처리 (분모 계산을 단 O(1)로 줄이기 위함)
    fact = [1] * (MAX_D + 3)
    invFact = [1] * (MAX_D + 3)
    for i in range(1, MAX_D + 3):
        fact[i] = (fact[i - 1] * i) % MOD
        
    # 페르마의 소정리를 이용한 팩토리얼 역원 계산
    invFact[MAX_D + 2] = pow(fact[MAX_D + 2], MOD - 2, MOD)
    for i in range(MAX_D + 1, -1, -1):
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD

    def get_Sd(K, d):
        """라그랑주 보간법을 이용해 1^d + 2^d + ... + K^d 를 O(d)에 계산"""
        p = d + 1  # S_d(K)는 (d+1)차 다항식
        
        # K가 다항식 차수보다 작거나 같으면 직접 계산이 더 빠르고 안전함
        if K <= p:
            ans = 0
            for i in range(1, K + 1):
                ans = (ans + pow(i, d, MOD)) % MOD
            return ans

        # 1단계: y_i = P(i) 값 계산 (i = 0 ~ p)
        # x 좌표가 0, 1, 2 ... p 인 점들의 y 좌표를 구함
        y = [0] * (p + 1)
        for i in range(1, p + 1):
            y[i] = (y[i - 1] + pow(i, d, MOD)) % MOD

        # 2단계: 분자 계산을 위한 Prefix, Suffix 배열 (O(d) 최적화의 핵심)
        pref = [1] * (p + 1)
        suff = [1] * (p + 1)
        
        pref[0] = K % MOD
        for i in range(1, p + 1):
            pref[i] = (pref[i - 1] * (K - i)) % MOD
            
        suff[p] = (K - p) % MOD
        for i in range(p - 1, -1, -1):
            suff[i] = (suff[i + 1] * (K - i)) % MOD

        # 3단계: 공식에 대입하여 P(K) 조합
        ans = 0
        for i in range(p + 1):
            # 분자: (K - 0)(K - 1)...(K - p) 에서 (K - i)만 제외한 곱
            num = 1
            if i > 0: num = (num * pref[i - 1]) % MOD
            if i < p: num = (num * suff[i + 1]) % MOD

            # 분모: i! * (p - i)! * (-1)^(p - i)
            den_inv = (invFact[i] * invFact[p - i]) % MOD
            if (p - i) % 2 == 1:
                den_inv = MOD - den_inv  # 음수 처리

            # 최종 항 = y_i * 분자 / 분모
            term = (y[i] * num) % MOD
            term = (term * den_inv) % MOD
            ans = (ans + term) % MOD

        return ans

    # 최종 정답 도출
    ans = 0
    invK = pow(k_val, MOD - 2, MOD)
    
    for d, count in vcnt.items():
        Sd = get_Sd(k_val, d)
        # 각 차수에 대해 (기댓값 * 해당 차수의 정점 개수) 누적
        evmd = (Sd * pow(invK, d, MOD)) % MOD
        ans = (ans + count * evmd) % MOD

    print(ans)

if __name__ == '__main__':
    solve()