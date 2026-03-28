import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    maxR, maxX = 1_000_001, 500_000
    p = [1]*(maxR+1); p[0] = p[1] = 0
    idx = 2
    while idx < maxR:
        if p[idx]: p[idx*idx:maxR+1:idx] = [0]*len(range(idx*idx, maxR+1, idx))
        idx += 1
    ps = [0]*(maxX+1)
    for x in range(1, maxX+1):
        if p[2*x+1]: ps[x] = ps[x-1]+1
        else: ps[x] = ps[x-1]
    q = int(input())
    ans = []
    for _ in range(q):
        L, R = map(int, input().split())
        ans.append(str(ps[R-1]-ps[L-1]))
    print('\n'.join(ans))
    return
if __name__ == '__main__':
    main()