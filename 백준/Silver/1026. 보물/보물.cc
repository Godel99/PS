import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort(); b.sort(reverse=True)
    s = 0
    for i in range(n): s += a[i]*b[i]
    print(s)
    return 0
if __name__ == '__main__':
    sys.exit(main())
