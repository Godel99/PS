import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    minv = float('inf')
    l = 0; r = n-1
    ans = [a[l], a[r]]
    while l < r:
        val = abs(a[l]+a[r])
        if minv > val: 
            minv = val
            ans = [a[l], a[r]]
            if minv == 0: break
        if a[l]+a[r] < 0: l += 1
        else: r -= 1
    print(*ans)      
    return 0
if __name__ == '__main__':
    sys.exit(main())