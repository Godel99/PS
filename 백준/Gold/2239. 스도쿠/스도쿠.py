import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

FULL = 0b1111111110

def main():
    board = [list(map(int, input())) for _ in range(9)]
    rowc, colc, boxc = [0]*9, [0]*9, [0]*9
    def update(r, c, n, s):
        bit = 1<<n
        if s:
            board[r][c] = n
            rowc[r] |= bit
            colc[c] |= bit
            boxc[(r//3)*3+(c//3)] |= bit
        else:
            board[r][c] = 0
            rowc[r] ^= bit
            colc[c] ^= bit
            boxc[(r//3)*3+(c//3)] ^= bit
    for r in range(9):
        for c in range(9):
            if board[r][c]:
                bit = 1<<board[r][c]
                rowc[r] |= bit
                colc[c] |= bit
                boxc[(r//3)*3+(c//3)] |= bit
    def avail(r, c): return ~(rowc[r] | colc[c] | boxc[(r//3)*3+(c//3)])&FULL
    def propa():
        while 1:
            flag = 0
            for r in range(9):
                for c in range(9):
                    if board[r][c] == 0:
                        ava = avail(r, c)
                        if ava and (ava & (ava-1)) == 0:
                            update(r, c, ava.bit_length()-1, 1)
            for r in range(9):
                arow = FULL&~rowc[r]
                while arow:
                    bit = arow&-arow
                    num = bit.bit_length()-1
                    nc, cnt = -1, 0
                    for c in range(9):
                        if board[r][c] == 0 and not (colc[c] & bit or boxc[(r//3)*3+(c//3)] & bit):
                            cnt += 1
                            nc = c
                            if cnt > 1: break
                    if cnt == 1:
                        update(r, nc, num, 1)
                        flag = 1
                    arow &= ~bit
            for c in range(9):
                acol = FULL&~colc[c]
                while acol:
                    bit = acol&-acol
                    num = bit.bit_length()-1
                    nr, cnt = -1, 0
                    for r in range(9):
                        if board[r][c] == 0 and not (rowc[r] & bit or boxc[(r//3)*3+(c//3)] & bit):
                            cnt += 1
                            nr = r
                            if cnt > 1: break
                    if cnt == 1:
                        update(nr, c, num, 1)
                        flag = 1
                    acol &= ~bit
            if not flag: break
    propa()
    blank = [(r, c) for r in range(9) for c in range(9) if board[r][c] == 0]
    def dfs(idx):
        if idx == len(blank):
            for row in board:
                print("".join(map(str, row)))
            sys.exit(0)
        r, c = blank[idx]
        ava = avail(r, c)
        while ava:
            bit = ava & -ava
            num = bit.bit_length() - 1
            update(r, c, num, True)
            dfs(idx + 1)
            update(r, c, num, False)
            ava &= ~bit
    dfs(0)
    return
if __name__ == "__main__":
    main()