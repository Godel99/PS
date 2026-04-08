import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import inf

def main():
    n = int(input())
    a = tuple(map(int, input().split()))
    l, r = 0, n-1
    minx= inf
    ans = [a[l], a[r]]
    while l < r:
        x = abs(a[l]+a[r])
        if minx > x:
            minx = x
            ans = [a[l], a[r]]
            if minx == 0: break
        if a[l]+a[r] < 0: l += 1
        else: r -= 1
    print(*ans)
    return
if __name__ == "__main__":
    main()