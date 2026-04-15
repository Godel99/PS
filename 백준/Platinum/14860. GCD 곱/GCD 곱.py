import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    n, m = map(int, input().split())
    if n > m: n, m = m, n
    size = n//3+1
    isp = bytearray([1])*size
    isp[0] = 0
    limit = int(n**0.5)
    for i in range(1, limit//3+1):
        if isp[i]:
            p = 3*i+1|1
            d, s, j = p*2, p*p, p*(p+4-2*(i&1))
            isp[s//3::d] = bytearray([0])*((size-1-s//3)//d+1)
            isp[j//3::d] = bytearray([0])*((size-1-j//3)//d+1)
    primes = [2, 3]+[3*i+1|1 for i in range(1, size) if isp[i]]
    ans = 1
    for p in primes:
        pi, ex = p, 0
        while pi <= n:
            ex = (ex+(n//pi)*(m//pi))
            pi *= p
        ans = ans*pow(p, ex%(MOD-1), MOD)%MOD
    print(ans)
    return
if __name__ == '__main__':
    main()