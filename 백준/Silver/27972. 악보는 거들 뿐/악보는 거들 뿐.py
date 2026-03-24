import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    m = int(input())
    p = list(map(int, input().split()))
    pre = p[0]
    pcnt = ncnt = ans = 1
    for i in range(1, m):
        if p[i-1] == p[i]: continue
        if p[i-1] > p[i]: ncnt += 1; pcnt = 1
        else: pcnt += 1; ncnt = 1
        ans = max(ans, pcnt, ncnt)       
    print(ans)
    return
if __name__ == '__main__':
    main()