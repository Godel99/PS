import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, m = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(n)]
    delta = ((1, 0), (-1, 0), (0, 1), (0, -1))
    board[0][0] = -1
    che = [(0, 0)]
    time = -1
    while che:
        nche = []
        while che:
            r, c = che.pop()
            for dr, dc in delta:
                nr, nc = r+dr, c+dc
                if 0 <= nr < n and 0 <= nc < m:
                    if board[nr][nc] < 0: continue
                    if board[nr][nc] == 0:
                        che.append((nr, nc))
                        board[nr][nc] = -1
                    elif board[nr][nc] == 1: board[nr][nc] = 2
                    else:
                        board[nr][nc] = -1
                        nche.append((nr, nc))
        che = nche
        time += 1
    print(time)
    return
if __name__ == '__main__':
    main()