import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    r, g, b = list(map(int, input().split()))
    for _ in range(n-1):
        nr, ng, nb = map(int, input().split())
        r, g, b = min(g, b)+nr, min(r, b)+ng, min(r, g)+nb
    print(min(r, g, b))
if __name__ == '__main__':
    main()