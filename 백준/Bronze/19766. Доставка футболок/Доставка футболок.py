import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n, k, t = map(int, input().split())
    s = list(map(int, input().split()))
    z = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        ans += s[i]
        if ans + k >= z[i]:
            ans = max(ans, z[i])
            ans += t
        else: ans += k
    print(ans)
if __name__ == '__main__':
    main()