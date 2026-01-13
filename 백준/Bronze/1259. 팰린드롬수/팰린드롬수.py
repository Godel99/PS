import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    while True:
        s = input()
        if s == '0': break
        if s == s[::-1]: print('yes')
        else: print('no')
if __name__ == '__main__':
    main()