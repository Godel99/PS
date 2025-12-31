import sys

def main():
    a = input()
    b = input()
    c = input()
    
    sys.stdout.write(f'{int(a)+int(b)-int(c)}\n')
    sys.stdout.write(f'{int(a+b)-int(c)}')
    
if __name__ == '__main__':
    main()