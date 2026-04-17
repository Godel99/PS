import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import inf

def main():
    cmd = [*map(int, input().split())]
    if not cmd or not cmd[0]: print(0); return
    cmd.pop()
    def cst(start, end):
        if start == 0: return 2
        if start == end: return 1
        if abs(start-end) == 2: return 4
        return 3
    dp = [[inf]*5 for _ in range(5)]
    dp[0][0] = 0
    for c in cmd:
        ndp = [[inf]*5 for _ in range(5)]
        for l in range(5):
            for r in range(5):
                if dp[l][r] == inf: continue
                if c != r: ndp[c][r] = min(ndp[c][r], dp[l][r]+cst(l, c))
                if c != l: ndp[l][c] = min(ndp[l][c], dp[l][r]+cst(r, c))
        dp = ndp
    print(min(map(min, dp)))
    return
if __name__ == "__main__":
    main()