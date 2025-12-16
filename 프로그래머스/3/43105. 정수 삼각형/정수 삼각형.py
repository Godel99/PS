def solution(triangle):
    dp = triangle[-1]
    for row in reversed(triangle[:-1]):
        dp = [row[j] + max(dp[j], dp[j+1]) for j in range(len(row))]
    return dp[0]