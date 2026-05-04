import sys
sys.setrecursionlimit(10**6)

def solution(n, m, x, y, r, c, k):
    dx, dy = (1, 0, 0, -1), (0, -1, 1, 0)
    dlru = ('d', 'l', 'r', 'u')
    dist = abs(x-r)+abs(y-c)
    if dist > k or (dist-k)&1: return 'impossible'
    flag = 0
    ans = []
    def dfs(cx, cy, d, path):
        nonlocal flag, ans
        if flag: return
        cdist = abs(cx-r)+abs(cy-c)
        if cdist > k-d or (k-d-cdist)&1: return
        if d == k:
            if  cx == r and cy == c: 
                ans = ''.join(path)
                flag = 1
            return
        for dir in range(4):
            nx, ny = cx+dx[dir], cy+dy[dir]
            if 1 <= nx <= n and 1 <= ny <= m:
                path.append(dlru[dir])
                dfs(nx, ny, d+1, path)
                path.pop()
    dfs(x, y, 0, [])
    return ans