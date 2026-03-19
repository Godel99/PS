import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    a = list(input().split())
    a.sort(key=lambda x: x*9, reverse=True)
    ans = ''.join(a)
    print('0' if ans[0] == '0' else ans)
if __name__ == '__main__':
    main()