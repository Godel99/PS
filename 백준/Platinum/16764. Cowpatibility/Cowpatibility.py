import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import Counter
from itertools import combinations

def main():
    n = int(input())
    ccnt = Counter()
    for _ in range(n):
        a = sorted(map(int, input().split()))
        for r in range(1, 6):
            for comb in combinations(a, r):
                ccnt[comb] += 1
    ans = n*(n-1)//2
    for comb, cnt in ccnt.items():
        if cnt < 2: continue
        if len(comb)&1: ans -= cnt*(cnt-1)//2
        else: ans += cnt*(cnt-1)//2
    print(ans)
    return
if __name__ == '__main__':
    main()