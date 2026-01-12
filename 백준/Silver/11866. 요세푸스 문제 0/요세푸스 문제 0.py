import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

from collections import deque

def main():
    n, k = map(int, input().split())
    q = deque(list(range(1, n+1)))
    i = 1
    print('<', end='')
    while q:
        j = q.popleft()
        if i % k == 0:
            print(j, end='')
            if q:
                print(end=', ')
        else:
            q.append(j)
        i += 1
    print('>')
if __name__ == '__main__':
    main()