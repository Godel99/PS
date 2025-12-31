def solution(s):
    n = len(s)
    length = 1
    idx = 0

    for idx in range(n):
        if idx + 1 < n and s[idx] == s[idx+1]:
            left = idx
            right = idx + 1
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            length = max(length, (right - left - 1))

        if idx - 1 >= 0 and idx + 1 < n and s[idx-1] == s[idx+1]:
            left = idx - 1
            right = idx + 1
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            length = max(length, (right - left - 1))
        
    return length
        