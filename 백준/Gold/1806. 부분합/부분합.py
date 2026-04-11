import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from math import inf

def main():
    n, s = map(int, input().split())
    a = [*map(int, input().split())]
    ans = inf
    l = suma = 0
    for r in range(n):
        suma += a[r]
        while suma >= s:
            ans = min(ans, r-l+1)
            suma -= a[l]
            l += 1
    print(0 if ans == inf else ans)
    return
if __name__ == "__main__":
    main()