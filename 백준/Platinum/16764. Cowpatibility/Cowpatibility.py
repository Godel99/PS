import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    v = []
    for _ in range(n):
        a = sorted(map(int, input().split()))
        for j in range(1, 32):
            tmp = []
            for k in range(5):
                if j>>k & 1: tmp.append(a[k])
            v.append(tuple(tmp))
    v.sort()
    ans = n*(n-1)//2; cnt = 1
    for i in range(1, len(v)):
        if v[i] == v[i-1]: cnt += 1
        else:
            ans += (-1 if len(v[i-1])&1 else 1)*cnt*(cnt-1)//2
            cnt = 1
    ans += (-1 if len(v[-1])&1 else 1)*cnt*(cnt-1)//2
    print(ans)
    return
if __name__ == '__main__':
    main()