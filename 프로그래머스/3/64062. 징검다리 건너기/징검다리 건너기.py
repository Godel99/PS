def solution(stones, k):
    left, right = 1, max(stones)

    while left <= right:
        mid = (left + right) // 2
        broken = 0

        for stone in stones:
            if stone < mid:
                broken += 1
                if broken == k:
                    break
            else:
                broken = 0

        if broken == k:
            right = mid - 1
        else:
            answer = mid
            left =  mid + 1

    return answer