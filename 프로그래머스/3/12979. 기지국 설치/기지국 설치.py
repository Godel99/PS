def solution(n, stations, w):
    cnt = 0
    cover = 2 * w + 1
    start = 1

    for s in stations:
        end = s - w
        if start < end:
            area = end - start
            cnt += (area + cover - 1) // cover
        start = s + w + 1
    
    if start <= n:
        area =  n - start + 1
        cnt += (area + cover - 1) // cover
    
    return cnt