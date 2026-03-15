import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    a, b = map(int, input().split())
    dq = deque([(a, 1)])
    while dq:
        cur, cnt = dq.popleft()
        if cur == b:
            print(cnt)
            return
        for nxt in [cur<<1, cur*10+1]:
            if nxt <= b:
                dq.append((nxt, cnt+1))
    print(-1)
if __name__ == '__main__':
    main()