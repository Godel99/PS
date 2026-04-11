import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    t = n = int(input()); n <<= 1
    ans = []
    while n:
        if n&1: ans.append(t); t -= 1
        t -= 1
        n >>= 1
    print(len(ans))
    print(*reversed(ans))
    return
if __name__ == "__main__":
    main()