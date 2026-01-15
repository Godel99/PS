import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()
    
def main():
    n = int(input())
    print(pow(n-1,2))
    for i in range(2, n+1): print(1, i)
if __name__ == '__main__':
    main()