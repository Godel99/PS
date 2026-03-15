import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    a, b, c = map(int, input().split())
    print(pow(a, b, c))
if __name__ == '__main__':
    main()