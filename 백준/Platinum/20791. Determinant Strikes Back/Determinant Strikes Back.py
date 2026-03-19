import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    data = sys.stdin.read().split()
    if not data: return
    idx = 0
    while idx < len(data):
        n, x = list(map(int, data[idx:idx+2]))
        idx += 2
        a = list(map(int,data[idx:idx+n]))
        idx += n
        b = list(map(int,data[idx:idx+n]))
        idx += n
        s = 0
        for i in range(n): s = (s+(a[i]*b[i]))%MOD
        print((pow(x, n, MOD)+(pow(x, n-1, MOD)*s)%MOD)%MOD)
if __name__ == '__main__':
    main()