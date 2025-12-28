import sys

input=sys.stdin.readline

def main():
    n = int(input())   
    
    for i in range(n):
        for j in range(i+1):
            sys.stdout.write('*')
        sys.stdout.write('\n')

if __name__ == '__main__':
    main()