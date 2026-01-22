import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    cnt = [0]*10001
    for _ in range(n): cnt[int(input())] += 1
    for i in range(1, 10001):
        for _ in range(cnt[i]): print(i)
    return 0
if __name__ == '__main__':
    sys.exit(main())