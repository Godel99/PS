import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from functools import cmp_to_key

def main():
    n = int(input())
    a = list(input().split())
    a.sort(key=cmp_to_key(lambda a, b: -1 if a+b > b+a else 1))
    ans = ''.join(a)
    print('0' if ans[0] == '0' else ans)
if __name__ == '__main__':
    main()