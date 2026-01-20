n, k = map(int, input().split())

result = 0

# k보다 큰 i에 대해서는 k mod i = k
if n > k:
    result += (n - k) * k
    n = k

# i = 1부터 n까지 k mod i의 합 계산
# 같은 몫을 가지는 구간을 묶어서 처리
i = 1
while i <= n:
    q = k // i  # k를 i로 나눈 몫
    r = k % i   # k를 i로 나눈 나머지
    
    # 같은 몫 q를 가지는 최대 i 찾기
    # k // next_i == q를 만족하는 최대 next_i
    if q == 0:
        next_i = n
    else:
        next_i = min(k // q, n)
    
    # i부터 next_i까지의 구간에서 k mod j의 합
    # k mod j = k - q * j 이므로
    # 구간 [i, next_i]에서의 합 = k * cnt - q * (i + ... + next_i)
    cnt = next_i - i + 1
    sum_range = (i + next_i) * cnt // 2
    result += k * cnt - q * sum_range
    
    i = next_i + 1

print(result)