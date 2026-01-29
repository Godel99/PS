import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

import heapq

def main():
    n = int(input())
    l = sorted([tuple(map(int, input().split())) for _ in range(n)], key=lambda x: x[1])
    hq = []
    for p, d in l:
        heapq.heappush(hq, p)
        if len(hq) > d: heapq.heappop(hq)
    print(sum(hq))
    return 0
if __name__ == '__main__':
    sys.exit(main())