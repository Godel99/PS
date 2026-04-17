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
    dp = [inf]*5; dp[0] = 0
    pre = 0
    for cur in cmd:
        minv = inf
        for i in range(5):
            minv = min(minv, dp[i]+cst(i, cur))
            dp[i] += cst(pre, cur)
        dp[pre] = minv
        pre = cur
    print(min(dp))
    return
if __name__ == "__main__":
    main()