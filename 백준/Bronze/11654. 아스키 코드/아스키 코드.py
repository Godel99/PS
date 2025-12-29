import sys

input=sys.stdin.readline

def main():
    c = input()
    sys.stdout.write(f'{ord(c[0])}')
 
if __name__ == '__main__':
    main()