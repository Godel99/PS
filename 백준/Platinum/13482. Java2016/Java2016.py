import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

from string import ascii_lowercase

def main():
    n = int(input())
    a_z = ascii_lowercase
    print('a=?max?')
    for i in range(1, 16): print(f'{a_z[i]}={a_z[i-1]}max{a_z[i-1]}')
    print('q=pmaxpmaxpmaxpmaxp')
    print('r=q-q')
    print('s=q/q')
    for i in range(19, 26): print(f'{a_z[i]}={a_z[i-1]}+{a_z[i-1]}')
    if n:
        ans = []
        bit = ['s', 't', 'u', 'v', 'w', 'x', 'y', 'z']
        for i in range(8):
            if n & (1<<i): ans.append(bit[i])
        print('+'.join(ans))
    else: print('r')
    return
if __name__ == "__main__":
    main()