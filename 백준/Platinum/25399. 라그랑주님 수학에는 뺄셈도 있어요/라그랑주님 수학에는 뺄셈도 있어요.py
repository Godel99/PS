import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from math import isqrt

def main():
    n = int(input())
    if n == 0: print('3\n+ 3\n+ 4\n- 5'); return
    re = 0
    if n < 0: re = 1; n = abs(n)
    pos, neg = [], []
    if isqrt(n)*isqrt(n) == n: pos.append(isqrt(n))
    elif n&1:
        pos.append((n+1)//2)
        neg.append((n+1)//2-1)
    elif n&3 == 0:
        pos.append((n>>2)+1)
        neg.append((n>>2)-1)
    else:
        flag = 1
        for i in range(1, 1000_000):
            n_i = n-i*i
            if n_i <= i*i: break
            if isqrt(n_i)*isqrt(n_i) == n_i:
                pos.append(isqrt(n_i))
                pos.append(i)
                flag = 0
                break
        if flag:
            pos.append(1000_003)
            n = 1000_003*1000_003-n
            neg.append((n+1)//2)
            pos.append((n+1)//2-1)
    if re: pos, neg = neg, pos
    print(len(pos)+len(neg))
    for p in pos: print(f'+ {p}')
    for n in neg: print(f'- {n}')
    return  
if __name__ == '__main__':
    main()