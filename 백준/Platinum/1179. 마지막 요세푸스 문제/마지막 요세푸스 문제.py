import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**7)

def josephus(n, k):
    if n == 1: return 0
    if n < k: return (josephus(n-1, k)+k)%n
    l = josephus(n-n//k, k) - n%k
    if l < 0: return l+n
    return l+l//(k-1)

def main():
    n, k = map(int, input().split())
    print(n) if k == 1 else print(josephus(n,k)+1)
if __name__ == '__main__':
    main()
