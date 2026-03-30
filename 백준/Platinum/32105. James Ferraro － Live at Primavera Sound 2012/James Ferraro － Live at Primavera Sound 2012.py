import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    N = int(input())
    isp = bytearray([1])*(N+1)
    isp[0] = isp[1] = 0
    isp[4::2] = bytearray([0]) * len(range(4, N + 1, 2))
    for i in range(3, int((N+1)**0.5)+1, 2):
        if isp[i]: isp[i*i:(N+1):i*2] = bytearray([0])*len(range(i*i, (N+1), i*2))
    ans = []
    while N > 7:
        r = ((3-N)%6+6)%6
        s = (N-1)-((N-1-r)%6+6)%6
        for L in range(s, 0, -6):
            if isp[(L+N)//3]:
                for i in range((N-L+1)//2): ans.append(f'{L+i} {N-i}')
                N = L-1
                break
    if N >= 6: ans.extend(('1 5', '2 4', '3 6'))
    elif N >= 4: ans.extend(('1 3', '2 4'))
    elif N == 3: ans.append('1 3')
    print(f'{len(ans)}\n'+'\n'.join(ans))
    return
if __name__ == '__main__':
    main()