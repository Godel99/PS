import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n_str = input()
    n = int(n_str)
    start = max(0, int(n) - (9 * len(n_str)))
    
    for i in range(start, n):
        total = i + sum(map(int, str(i)))
        if total == n:
            print(i)
            break
    else:
        print(0)
        
if __name__ == '__main__':
    main()
