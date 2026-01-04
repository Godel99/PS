def solution(a):
    n = len(a)
    if n < 3:
        cnt = n
    else:
        cnt = 2

    right_min = [0] * n
    right_min[n-1] = a[n-1]

    Lmin = a[0]
    for i in range(n-2, 0, -1):
        right_min[i] = min(right_min[i+1], a[i+1])

    for i in range(1, n-1):
        Lmin = min(Lmin, a[i-1])

        if a[i] > Lmin and a[i] > right_min[i]:
            continue
        else:
            cnt += 1

    return cnt