import sys
from math import gcd

def main():
    data = sys.stdin.buffer.read().split()
    ptr = 0
    N = int(data[ptr]); ptr += 1
    M = int(data[ptr]); ptr += 1

    xs = [int(data[ptr + 3*i]) - 1 for i in range(M)]
    ys = [int(data[ptr + 3*i + 1]) - 1 for i in range(M)]
    zs = [int(data[ptr + 3*i + 2]) for i in range(M)]

    D = [1] * N

    # 각 소수별로 각 위치에서 필요한 최대 지수를 차이 배열로 계산
    for p in [2, 3, 5, 7, 11, 13]:
        # p^max_e <= 16인 최대 지수
        max_e, pk = 0, p
        while pk <= 16:
            max_e += 1
            pk *= p

        # 각 제약조건의 z에서 p의 지수 계산
        vp = [0] * M
        for i in range(M):
            t = zs[i]
            while t % p == 0:
                vp[i] += 1
                t //= p

        max_exp = [0] * N

        # 지수 e별로 차이 배열(difference array)로 범위 업데이트
        for e in range(1, max_e + 1):
            diff = [0] * (N + 1)
            for i in range(M):
                if vp[i] >= e:
                    diff[xs[i]] += 1
                    diff[ys[i] + 1] -= 1
            cur = 0
            for i in range(N):
                cur += diff[i]
                if cur > 0:
                    max_exp[i] = e  # 낮은 e→높은 e 순서로 덮어쓰면 max와 동일

        pw = [p**e for e in range(max_e + 1)]
        for i in range(N):
            if max_exp[i]:
                D[i] *= pw[max_exp[i]]

    # Sparse Table 구성 (구간 GCD O(1) 질의)
    LOG = N.bit_length()
    table = [D[:]]
    for j in range(LOG):
        half = 1 << j
        prev = table[j]
        table.append([
            gcd(prev[i], prev[i + half]) if i + half < N else prev[i]
            for i in range(N)
        ])

    def range_gcd(l, r):
        k = (r - l + 1).bit_length() - 1
        return gcd(table[k][l], table[k][r - (1 << k) + 1])

    # 모든 조건 검증
    for i in range(M):
        if range_gcd(xs[i], ys[i]) != zs[i]:
            sys.stdout.write("Impossible\n")
            return

    sys.stdout.write(' '.join(map(str, D)) + '\n')

main()