import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

dx, dy = (1, -1, 0, 0), (0, 0, 1, -1)

def main():
    r, c = map(int, input().split())
    board = [list(map(lambda x: ord(x)-65, input())) for _ in range(r)]
    s = {(0, 0, 1<<board[0][0])}
    maxdist = 1
    while s:
        x, y, bit = s.pop()
        if maxdist == 26: break
        for dir in range(4):
            nx, ny = x+dx[dir], y+dy[dir]
            if 0 <= nx < r and 0 <= ny <c and not bit & 1<<board[nx][ny]:
                nbit = bit|1<<board[nx][ny]
                maxdist = max(maxdist, nbit.bit_count())
                s.add((nx, ny, nbit))
    print(maxdist)
    return
if __name__ == '__main__':
    main()