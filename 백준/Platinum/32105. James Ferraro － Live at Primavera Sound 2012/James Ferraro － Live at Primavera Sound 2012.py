import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    N = int(input())
    isp = bytearray([1])*(N+1)
    isp[0] = isp[1] = 0
    for i in range(2, int((N+1)**0.5)+1):
        if isp[i]: isp[i*i:(N+1):i] = bytearray([0])*len(range(i*i, (N+1), i))
    ans = []
    while N > 7:
        flag = 0
        for LL in range(N-1, 0, -1):
            if (LL+N)%3 == 0 and (LL+N)&1:
                for L in range(LL, 0, -6):
                    if isp[(L+N)//3]:
                        for i in range((N-L+1)//2): ans.append(f'{L+i} {N-i}')
                        N = L-1
                        flag = 1
                        break
            if flag: break
    if N >= 6: ans.extend(('1 5', '2 4', '3 6'))
    elif N >= 4: ans.extend(('1 3', '2 4'))
    elif N == 3: ans.append('1 3')
    print(f'{len(ans)}\n'+'\n'.join(ans))
    return
if __name__ == '__main__':
    main()