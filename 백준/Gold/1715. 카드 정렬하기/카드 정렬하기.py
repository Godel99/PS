import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

import heapq

def main():
    n = int(input())
    hq = [int(input()) for _ in range(n)]
    heapq.heapify(hq)
    ans = []
    while len(hq) > 1:
        a = heapq.heappop(hq)
        b = heapq.heappop(hq)
        ans.append(a); ans.append(b)
        heapq.heappush(hq, a+b)
    print(sum(ans))
    return 0
if __name__ == '__main__':
    sys.exit(main())