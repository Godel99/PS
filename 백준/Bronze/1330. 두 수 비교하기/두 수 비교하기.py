import sys

input=sys.stdin.readline

def main():
    a, b = map(int, input().split())
    if a > b:
        sys.stdout.write('>')
    elif a < b:
        sys.stdout.write('<')
    else:
        sys.stdout.write('==')

if __name__ == '__main__':
    main()