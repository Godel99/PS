import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from string import ascii_lowercase

def main():
    n = int(input())
    a_z = ascii_lowercase
    print('a=?max?')
    for i in range(1, 16):
        cur, pre = a_z[i], a_z[i-1]
        print(f'{cur}={pre}max{pre}')
    print('q=pmaxpmaxpmaxpmaxp')
    print('r=q/q')
    print('s=q-q')
    pre = 'r'
    bit = ['r']
    for i in range(19, 26):
        print(f'{a_z[i]}={pre}+{pre}')
        bit.append(a_z[i])
        pre = a_z[i]
    if n:
        ans = []
        for i in range(8):
            if n & (1<<i): ans.append(bit[i])
        print('+'.join(ans))
    else: print('s')
    return
if __name__ == "__main__":
    main()