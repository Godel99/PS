import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from math import sqrt

def main():
    maxR, maxX = 1000001, 500000
    isp = [1]*(maxR+1)
    isp[0] = isp[1] = 0
    for i in range(2, int(sqrt(maxR))+1):
        if isp[i]:
            for j in range(i*i, maxR+1, i): isp[j] = 0
    pres = [0]*(maxX+1)
    for x in range(1, maxX+1):
        if isp[2*x+1]: pres[x] = pres[x-1]+1
        else: pres[x] = pres[x-1]
    q = int(input())
    ans = []
    for _ in range(q):
        L, R = map(int, input().split())
        ans.append(str(pres[R-1]-pres[L-1]))
    print('\n'.join(ans))
    return
if __name__ == '__main__':
    main()