import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n, k = map(int, input().split())
    blocked_list = list(map(int, input().split()))

    dp = [False] * (n + 1)
    blocked = [False] * (n + 1)
    
    for b in blocked_list:
        if b <= n:
            blocked[b] = True

    for x in range(n, -1, -1):
        for d in range(1, k+1):
            y = x + d
            if y > n:
                continue
            if blocked[y]:
                continue
            if not dp[y]:
                dp[x] = True
                break

    for i in range(1, k + 1):
        if i > n:
            continue
        if blocked[i]:
            continue
        if not dp[i]:
            print(1)
            return
    print(0)

if __name__ == '__main__':
    main()