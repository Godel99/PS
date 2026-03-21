import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from itertools import combinations
from math import inf

def main():
    n, m = map(int, input().split())
    house, chicken = [], []
    for r in range(n):
        row = list(map(int, input().split()))
        for c in range(n):
            if row[c] == 1: house.append((r, c))
            elif row[c] == 2: chicken.append((r, c))
    h_len, c_len = len(house), len(chicken)
    dist = [[abs(hr-cr)+abs(hc-cc) for cr, cc in chicken] for hr, hc in house]
    mindist = inf
    for com in combinations(range(c_len), m):
        curdist = 0
        for h_i in range(h_len):
            minhdist = inf
            for c_i in com: minhdist = min(minhdist, dist[h_i][c_i])
            curdist += minhdist
            if curdist >= mindist: break
        else: mindist = min(curdist, mindist)
    print(mindist)
    return
if __name__ == '__main__':
    main()