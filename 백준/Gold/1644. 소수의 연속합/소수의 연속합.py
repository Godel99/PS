import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    if n == 1: print(0); return
    isp = bytearray([1])*(n+1)
    isp[0] = isp[1] = 0
    isp[4::2] = bytearray([0]) * len(range(4, n+1, 2))
    for i in range(3, int((n+1)**0.5)+1, 2):
        if isp[i]: isp[i*i:(n+1):i*2] = bytearray([0])*len(range(i*i, (n+1), i*2))
    primes = [i for i, v in enumerate(isp) if v]
    ans = sp = l = 0
    for rp in primes:
        sp += rp
        while sp > n:
            sp -= primes[l]
            l += 1
        if sp == n: ans += 1
    print(ans)
    return
if __name__ == "__main__":
    main()