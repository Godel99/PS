import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

import heapq

def main():
    n = int(input())
    route = []
    for _ in range(n):
        s, e = map(int, input().split())
        if s > e: s, e = e, s
        route.append((s, e))
    route.sort(key=lambda x: x[1])
    d = int(input())
    hq = []
    ans = 0
    for s, e in route:
        if abs(s-e) > d: continue
        heapq.heappush(hq, s)
        while hq and hq[0] < e-d: heapq.heappop(hq)
        ans = max(ans, len(hq))
    print(ans)
    return  
if __name__ == '__main__':
    main()