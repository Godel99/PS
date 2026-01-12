import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    s = input()
    even = odd = 0
    for c in s:
        if int(c) & 1: odd += 1
        else: even += 1
    if odd > even: print(1)
    elif odd < even: print(0)
    else: print(-1)
if __name__ == '__main__':
    main()