import sys

input=sys.stdin.readline

def main():
    n = int(input())
    if (n % 4 == 0) and (n % 100 != 0 or n % 400 == 0):
        sys.stdout.write(str(1))
    else:
        sys.stdout.write(str(0))

if __name__ == '__main__':
    main()