import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    minv = float('inf')
    ans = []
    for i in range(n-2):
        l, r = i+1, n-1
        while l < r:
            v = a[i]+a[l]+a[r]
            if minv > abs(v):
                minv = abs(v)
                ans = [a[i], a[l], a[r]]
                if minv == 0: print(*ans); return
            if v < 0: l += 1
            else: r -= 1
    print(*ans)
    return
if __name__ == "__main__":
    main()