import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    k = int(input())
    ans = ['0'] * 100
    hands = ['2'] * 100
    for i in range(100):
        hands[i] = '0'
        print('?', ''.join(hands))
        sys.stdout.flush()
        hands[i] = '2'
        newk = int(input())
        if k < newk: ans[i] = '2'
        elif k == newk: ans[i] = '0'
        else: ans[i] = '5'
    print('!', ''.join(ans))
    sys.stdout.flush()
if __name__ == '__main__':
    main()