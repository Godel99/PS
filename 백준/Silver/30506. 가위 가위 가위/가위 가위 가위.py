import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    k = int(input())
    sys.stdout.flush()
    ans = ['0'] * 100
    s = ['2'] * 100
    for i in range(100):
        s[i] = '0'
        print("?", ''.join(s))
        sys.stdout.flush()
        newk = int(input())
        if k < newk: ans[i] = '2'
        elif k == newk: ans[i] = '0'
        else: ans[i] = '5'
        s[i] = '2'
    print('!', ''.join(ans))
    sys.stdout.flush()
if __name__ == '__main__':
    main()