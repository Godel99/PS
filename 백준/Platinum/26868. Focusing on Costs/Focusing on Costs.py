import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    a, b = map(int, input().split())
    a *= a; b *= b
    ans = []
    def gcd(a, b):
        if a == 0: return
        if a == b: 
            ans.append('cos'); 
            return
        if a > b:
            ans.extend(['tan', 'acos', 'sin', 'atan'])
            gcd(b, a)
            return
        ans.extend(['sin', 'atan'])
        gcd(a, b-a)
        return
    gcd(a, b)
    print(len(ans))
    print(*reversed(ans))
    return
if __name__ == "__main__":
    main()