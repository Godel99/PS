import sys

input=sys.stdin.readline

def main():
    for line in sys.stdin:
        a, b = map(int, line.split())
        if a == 0 and b ==0:
            break
        sys.stdout.write(str(a + b) + '\n')
 
if __name__ == '__main__':
    main()