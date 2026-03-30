import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    a = list(map(int, input().split()))
    up, down = [1]*n, [1]*n
    for i in range(n):
        for j in range(i):
            if a[j] < a[i]: up[i] = max(up[i], up[j]+1)
    for i in range(n-1, -1, -1):
        for j in range(i+1, n):
            if a[j] < a[i]: down[i] = max(down[i], down[j]+1)
    ans = max(up[i]+down[i]-1 for i in range(n))
    print(ans)
    return
if __name__ == '__main__':
    main()