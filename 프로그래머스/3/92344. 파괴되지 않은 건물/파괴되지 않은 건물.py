def solution(board, skill):
    n = len(board)
    m = len(board[0])

    diff = [[0] * (m+1) for _ in range(n+1)]

    for s in skill:
        t, r1, c1, r2, c2, d = s
        
        if t == 1:
            d = -d

        diff[r1][c1] += d
        diff[r1][c2+1] -= d
        diff[r2+1][c1] -= d
        diff[r2+1][c2+1] += d
    
    for i in range(n):
        for j in range(1, m):
            diff[i][j] += diff[i][j-1]

    for j in range(m):
        for i in range(1, n):
            diff[i][j] += diff[i-1][j]
    answer = 0

    for i in range(n):
        for j in range(m):
            if board[i][j] + diff[i][j] > 0:
                answer += 1
            
    return answer