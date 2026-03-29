import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    maxV = n+1
    isp = bytearray([1])*maxV
    isp[0] = isp[1] = 0
    for i in range(2, int(maxV**0.5)+1):
        if isp[i]: isp[i*i:maxV:i] = bytearray([0])*len(range(i*i, maxV, i))
    ans = []
    R = n
    while R > 7:
        flag = 0
        for LL in range(R-1, 0, -1):
            if (LL+R)%3 == 0 and isp[(LL+R)//3]:
                for i in range((R-LL+1)//2): ans.append(f'{LL+i} {R-i}')
                R = LL-1
                flag = 1
                break
            if flag: break
    if R >= 6: ans.extend(('1 5', '2 4', '3 6'))
    elif R >= 4: ans.extend(('1 3', '2 4'))
    elif R == 3: ans.append('1 3')
    print(f'{len(ans)}\n'+'\n'.join(ans))
    return
if __name__ == '__main__':
    main()