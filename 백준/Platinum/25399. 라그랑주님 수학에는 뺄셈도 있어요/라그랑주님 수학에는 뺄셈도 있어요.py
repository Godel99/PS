import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from math import isqrt

def main():
    n = int(input())
    op = ['-','+'] if n < 0 else ['+', '-']
    n = abs(n)
    if n == 0: print('3\n+ 5\n- 4\n- 3\n'); return
    if n == 2: print(f'3\n{op[0]} 6\n{op[1]} 5\n{op[1]} 3\n'); return
    r = isqrt(n)
    if r*r == n: print(f'1\n{op[0]} {r}\n'); return
    if n&1: print(f'2\n{op[0]} {n//2+1}\n{op[1]} {n//2}'); return
    if n&3 == 0: print(f'2\n{op[0]} {n//4+1}\n{op[1]} {n//4-1}'); return
    l = isqrt(n//2)
    for p in range(1, l+1):
        t = n-p*p
        re = isqrt(t)
        if re*re == t: print(f'2\n{op[0]} {re}\n{op[0]} {p}'); return
    print(f'3\n{op[1]} 1\n{op[0]} {n//2+1}\n{op[1]} {n//2}\n')
    return  
if __name__ == '__main__':
    main()