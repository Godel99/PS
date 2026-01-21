import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

from math import sqrt

def main():
    n, k = map(int, input().split())
    sq = int(sqrt(k)); ans = 0
    for i in range(1, min(k//sq, n)+1): ans += k%i
    for i in range(1, sq):
        l = k//(i+1)+1; r = min(k//i, n)
        if l > r: continue
        ans += k*(r-l+1)-(l+r)*(r-l+1)*i//2
    ans += k*max(0, n-k)
    print(ans)
    return 0
if __name__ == '__main__':
    sys.exit(main())
