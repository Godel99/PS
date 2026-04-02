import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

dr, dc = (1, -1, 0, 0), (0, 0, 1, -1)

def main():
    R, C, T= map(int, input().split())
    room = [list(map(int, input().split())) for _ in range(R)]
    clean = -1
    for r in range(R):
        if room[r][0] == -1: clean = r; break
    def spread():
        tmp = [[0]*C for _ in range(R)]
        for r in range(R):
            for c in range(C):
                if room[r][c] > 0:
                    a = room[r][c]//5
                    if a == 0: continue
                    cnt = 0
                    for d in range(4):
                        nr, nc = r+dr[d], c+dc[d]
                        if 0 <= nr < R and 0 <= nc < C and room[nr][nc] != -1:
                            tmp[nr][nc] += a
                            cnt += 1
                    room[r][c] -= a*cnt
        for r in range(R):
            for c in range(C):
                room[r][c] += tmp[r][c]
    def rot_top(top):
        for r in range(top-1, 0, -1): room[r][0] = room[r-1][0]
        for c in range(C-1): room[0][c] = room[0][c+1]
        for r in range(top): room[r][C-1] = room[r+1][C-1]
        for c in range(C-1, 1, -1): room[top][c] = room[top][c-1]
        room[top][1] = 0
    def rot_bot(bot):
        for r in range(bot+1, R-1): room[r][0] = room[r+1][0]
        for c in range(C-1): room[R-1][c] = room[R-1][c+1]
        for r in range(R-1, bot, -1): room[r][C-1] = room[r-1][C-1]
        for c in range(C-1, 1, -1): room[bot][c] = room[bot][c-1]
        room[bot][1] = 0
    for _ in range(T):
        spread()
        rot_top(clean)
        rot_bot(clean+1)
    print(sum(map(sum, room))+2)
    return  
if __name__ == '__main__':
    main()