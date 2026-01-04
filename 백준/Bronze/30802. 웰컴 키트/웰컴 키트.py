import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    candidate = list(map(int, input().split()))
    t, p = map(int, input().split())

    total = 0
    for c in candidate:
        total += ((c - 1) // t + 1)

    print(total)
    print(n // p, n % p)
    
if __name__ == '__main__':
    main()