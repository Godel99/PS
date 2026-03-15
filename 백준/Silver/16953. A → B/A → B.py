import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    a, b = map(int, input().split())
    cnt = 1
    while b > a:
        if b&1 == 0: b >>= 1
        elif b%10 == 1: b //= 10
        else: break
        cnt += 1
    print(cnt if b == a else -1)
if __name__ == '__main__':
    main()