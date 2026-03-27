import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    v1, v2, v3 = [0]*n, [0]*n*2, [0]*n*2
    cnt = 0
    def dfs(r):
        nonlocal cnt
        if r == n: cnt += 1; return
        for c in range(n):
            if not v1[c] and not v2[r+c] and not v3[r-c+n]:
                v1[c] = v2[r+c] = v3[r-c+n] = 1
                dfs(r+1)
                v1[c] = v2[r+c] = v3[r-c+n] = 0
    dfs(0)
    print(cnt)
    return
if __name__ == '__main__':
    main()