import heapq

def solution(board):
    n = len(board)
    INF = float('inf')
    
    # dp[r][c][dir] : (r,c)에 dir 방향으로 도착했을 때 최소 비용
    dp = [[[INF] * 4 for _ in range(n)] for _ in range(n)]
    
    # 방향: 상, 우, 하, 좌
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    
    pq = []
    
    # 시작점에서 가능한 두 방향만 초기화
    if board[0][1] == 0:
        dp[0][1][1] = 100
        heapq.heappush(pq, (100, 0, 1, 1))
    if board[1][0] == 0:
        dp[1][0][2] = 100
        heapq.heappush(pq, (100, 1, 0, 2))
    
    while pq:
        cost, r, c, dir = heapq.heappop(pq)
        
        if cost > dp[r][c][dir]:
            continue
        
        for ndir in range(4):
            nr = r + dx[ndir]
            nc = c + dy[ndir]
            
            if nr < 0 or nr >= n or nc < 0 or nc >= n:
                continue
            if board[nr][nc] == 1:
                continue
            
            ncost = cost + (100 if ndir == dir else 600)
            
            if ncost < dp[nr][nc][ndir]:
                dp[nr][nc][ndir] = ncost
                heapq.heappush(pq, (ncost, nr, nc, ndir))
    
    return min(dp[n-1][n-1])

# def solution(board):
#     n = len(board)
#     INF = float('inf')
#     dp = [[[INF] * 4 for _ in range(n)] for _ in range(n)] 
    
#     dx = [-1, 0, 1, 0]
#     dy = [ 0, 1, 0,-1]

#     min_heap =[]

#     if board[0][1] == 0:
#         heapq.heappush(min_heap, (100, 0, 1, 1))
#         dp[0][1][1] = 100
#     if board[1][0] == 0:
#         heapq.heappush(min_heap, (100, 1, 0, 2))
#         dp[1][0][2] = 100

#     while min_heap:
#         cost, r, c, dir = heapq.heappop(min_heap)

#         if cost > dp[r][c][dir]:
#             continue

#         for ndir in range(4):
#             nr = r + dx[ndir]
#             nc = c + dy[ndir]

#             if nr < 0 or nr >= n:
#                 continue
#             if nc < 0 or nc >= n:
#                 continue
#             if board[nr][nc] == 1:
#                 continue

#             if ndir == dir:
#                 ncost = cost + 100
#             else:
#                 ncost = cost + 600
            
#             if ncost < dp[nr][nc][ndir]:
#                 dp[nr][nc][ndir] = ncost
#                 heapq.heappush(min_heap, (ncost, nr, nc, ndir))

#     return min(dp[n-1][n-1])