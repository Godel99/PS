import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import Counter

def main():
    n = int(input())
    ccnt = Counter()
    for _ in range(n):
        a = sorted(map(int, input().split()))
        for j in range(1, 32):
            comb = []
            for k in range(5):
                if j>>k & 1: comb.append(a[k])
            ccnt[tuple(comb)] += 1
    ans = n*(n-1)//2
    for comb, cnt in ccnt.items():
        if cnt < 2: continue
        if len(comb)&1: ans -= cnt*(cnt-1)//2
        else: ans += cnt*(cnt-1)//2
    print(ans)
    return
if __name__ == '__main__':
    main()