def solution(sequence):
    A = []
    B = []
    n = len(sequence)
    for i, v in enumerate(sequence):
        if i % 2:
            A.append(-v)
            B.append(v)
        else:
            A.append(v)
            B.append(-v)

    for i in range(1, n):
        A[i] = max(A[i], A[i-1]+A[i])
        B[i] = max(B[i], B[i-1]+B[i])

    return max(max(A), max(B))
    