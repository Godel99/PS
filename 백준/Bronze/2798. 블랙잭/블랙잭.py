import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    cards = list(map(int, input().split()))
    msc = 0
    
    for i in range(n):
        for j in range(i+1,n):
            for k in range(j+1, n):
                cs = cards[i]+cards[j]+cards[k]
                if cs <= m:
                    msc = max(msc, cs)
    print(msc)
if __name__ == '__main__':
    main()