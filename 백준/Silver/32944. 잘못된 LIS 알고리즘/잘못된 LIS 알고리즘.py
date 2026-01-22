import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def main():
    n, m, k = map(int, input().split())
    if n == m: print(-1); return 0
    ans = []
    for i in range(1, k): ans.append(i)
    ans.append(n)
    for i in range(k, m): ans.append(i)
    for i in range(n-1, m-1, -1): ans.append(i)
    print(*ans)
    return 0
if __name__ == '__main__':
    sys.exit(main())