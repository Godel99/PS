import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    maxR, maxX = 1000001, 500000
    isp = bytearray([1])*(maxR+1)
    isp[0] = isp[1] = 0
    isp[4::2] = bytearray([0]) * len(range(4, maxR + 1, 2))
    for i in range(3, int((maxR+1)**0.5)+1, 2):
        if isp[i]: isp[i*i:(maxR+1):i*2] = bytearray([0])*len(range(i*i, (maxR+1), i*2))
    ps = [0]*(maxX+1)
    for x in range(1, maxX+1):
        if isp[2*x+1]: ps[x] = ps[x-1]+1
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