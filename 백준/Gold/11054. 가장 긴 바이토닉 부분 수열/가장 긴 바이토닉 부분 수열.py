import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from bisect import bisect_left

def main():
    n = int(input())
    a = list(map(int, input().split()))
    def LIS(a):
        n = len(a)
        lst = []
        ret = [0]*n
        for i in range(n):
            idx = bisect_left(lst, a[i])
            if idx == len(lst): lst.append(a[i])
            else: lst[idx] = a[i]
            ret[i] = len(lst)
        return ret
    up, down = LIS(a), LIS(a[::-1])[::-1]
    ans = 0
    for i in range(n): ans = max(ans, up[i]+down[i]-1)
    print(ans)
    return
if __name__ == '__main__':
    main()