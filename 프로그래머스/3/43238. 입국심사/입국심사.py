def solution(n, times):
    left = min(times)
    right = max(times) * n
    
    while left <= right:
        mid = (left + right) // 2
        m = sum(mid // t for t in times)

        if m < n:
            left = mid + 1
        else:
            right = mid - 1
    
    return left