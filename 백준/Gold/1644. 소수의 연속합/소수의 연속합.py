import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    if n == 1: print(0); return
    if n < 5: print(1 if n in {2, 3} else 0); return
    size = n//3+1
    isp = [1]*size
    isp[0] = 0
    limit = int(n**0.5)
    for i in range(1, limit//3+1):
        if isp[i]:
            p = 3*i+1|1
            d, s, j = p*2, p*p, p*(p+4-2*(i&1))
            isp[s//3::d] = [0]*((size-1-s//3)//d+1)
            isp[j//3::d] = [0]*((size-1-j//3)//d+1)
    primes = [2, 3]+[3*i+1|1 for i in range(1, size) if isp[i]]
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