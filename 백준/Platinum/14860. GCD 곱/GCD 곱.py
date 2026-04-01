import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

MOD = 1_000_000_007

def main():
    n, m = map(int, input().split())
    if n > m: n, m = m, n
    isp = bytearray([1])*(n+1)
    isp[0] = isp[1] = 0
    primes = []
    for i in range(2, n+1):
        if isp[i]: primes.append(i)
        for p in primes:
            if i*p > n: break
            isp[i*p] = 0
            if i%p == 0: break
    ans = 1
    for p in primes:
        pi = p
        ex = 0
        while pi <= n:
            ex = (ex+(n//pi)*(m//pi))
            pi *= p
        ans = ans*pow(p, ex%(MOD-1), MOD)%MOD
    print(ans)
    return
if __name__ == '__main__':
    main()