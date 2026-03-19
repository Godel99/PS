import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    a, b, c = map(int, input().split())
    maxdp, mindp = [a, b, c], [a, b, c]
    for i in range(n-1):
        a, b, c = map(int, input().split())
        maxdp = [max(maxdp[:2])+a, max(maxdp)+b, max(maxdp[1:])+c]
        mindp = [min(mindp[:2])+a, min(mindp)+b, min(mindp[1:])+c]
    print(max(maxdp), min(mindp))
if __name__ == '__main__':
    main()