def solution(sticker):
    n = len(sticker)

    if n == 1:
        return sticker[0]
    if n == 2:
        return max(sticker)
    
    dp1 = max(sticker[0], sticker[1])
    dp2 = sticker[0]

    for i in range(2, n-1):
        cur = max(dp1, dp2 + sticker[i])
        dp1, dp2 = cur, dp1

    first_sum = dp1

    dp1 = max(sticker[1], sticker[2])
    dp2 = sticker[1]

    for i in range(3, n):
        cur = max(dp1, dp2 + sticker[i])
        dp1, dp2 = cur, dp1

    second_sum = dp1

    return max(first_sum, second_sum)
