import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    a, b = map(int, input().split())
    a *= a; b *= b
    ans = []
    while a != b:
        if a < b:
            b -= a
            ans.extend(['sin', 'atan'])
        else:
            a, b = b, a
            ans.extend(['tan', 'acos', 'sin', 'atan'])
    ans.append('cos')
    print(len(ans))
    print(*reversed(ans))
    return
if __name__ == "__main__":
    main()