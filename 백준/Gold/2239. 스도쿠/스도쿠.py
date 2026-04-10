import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    board = [list(map(int, input())) for _ in range(9)]
    blank = [(r, c) for r in range(9) for c in range(9) if board[r][c] == 0]
    rowc = [[0]*10 for _ in range(9)]
    colc = [[0]*10 for _ in range(9)]
    boxc = [[0]*10 for _ in range(9)]
    for r in range(9):
        for c in range(9):
            if board[r][c]:
                num = board[r][c]
                rowc[r][num] = colc[c][num] = boxc[(r//3)*3+(c//3)][num] = 1
    def dfs(idx):
        if idx == len(blank):
            for row in board: print(''.join(map(str, row)))
            exit(0)
        r, c = blank[idx]
        for num in range(1, 10):
            if not rowc[r][num] and not colc[c][num] and not boxc[(r//3)*3+(c//3)][num]:
                rowc[r][num] = colc[c][num] = boxc[(r//3)*3+(c//3)][num] = 1
                board[r][c] = num
                dfs(idx+1)
                rowc[r][num] = colc[c][num] = boxc[(r//3)*3+(c//3)][num] = 0
                board[r][c] = 0
    dfs(0)
    return
if __name__ == "__main__":
    main()