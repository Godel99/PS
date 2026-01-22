import sys
def print(*args, sep=" ", end="\n"): sys.stdout.write(sep.join(map(str, args)) + end)
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    ans = []
    for _ in range(n): 
        age, name = input().split()
        ans.append((int(age), name))
    ans.sort(key=lambda x: x[0])
    for a in ans: print(a[0], a[1])
    return 0
if __name__ == '__main__':
    sys.exit(main())