import sys

input=sys.stdin.readline

def main():
    p = 1000000007
    n = int(input())
    l = n - n % 255
    x = 0
    
    for i in range(l, n+1):
        x -= i
        x = abs(x)
        if i % 3 == 0: 
            x = (x * i) % p
        if i % 15 == 0:
            x &= i
        if i % 63 == 0:
            x ^= i
        if i % 255 == 0:
            x |= i
        if i % 1023 == 0:
            x = (x * pow(2, i, p)) % p
    
    sys.stdout.write(str(x))

if __name__ == '__main__':
    main()