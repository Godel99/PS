import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    MOD = 1234567891
    n = int(input())
    s = input()
    h = 0
    for i, c in enumerate(s):
        h = (h + (ord(c) - ord('a') + 1) * pow(31, i, MOD)) % MOD
    print(h)
if __name__ == '__main__':
    main()