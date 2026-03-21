import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from itertools import combinations
from math import inf

def main():
    n, m = map(int, input().split())
    hou, chi = [], []
    for r in range(n):
        row = list(map(int, input().split()))
        for c in range(n):
            if row[c] == 1: hou.append((r, c))
            elif row[c] == 2: chi.append((r, c))
    houl, chil = len(hou), len(chi)
    dist = [[abs(hr-cr)+abs(hc-cc) for cr, cc in chi] for hr, hc in hou]
    mindist = inf
    for com in combinations(range(chil), m):
        curdist = 0
        for h_i in range(houl):
            minhdist = inf
            for c_i in com: minhdist = min(minhdist, dist[h_i][c_i])
            curdist += minhdist
            if curdist >= mindist: break
        else: mindist = min(curdist, mindist)
    print(mindist)
    return
if __name__ == '__main__':
    main()