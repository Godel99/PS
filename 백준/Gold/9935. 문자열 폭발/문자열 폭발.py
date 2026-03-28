import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    s, t = input(), list(input())
    n, lc = len(t), t[-1]
    ans = []
    for c in s:
        ans.append(c)
        if c == lc and ans[-n:] == t: del ans[-n:]
    print(''.join(ans) if ans else 'FRULA')
    return
if __name__ == '__main__':
    main()