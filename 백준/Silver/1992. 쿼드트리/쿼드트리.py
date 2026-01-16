import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()
    
def main():
    n = int(input())
    p = [list(input().strip()) for _ in range(n)]
    def dfs(x, y, size):
        t = p[x][y]
        for i in range(x, x+size):
            for j in range(y, y+size):
                if p[i][j] != t:
                    h = size // 2
                    return '('+dfs(x, y, h)+dfs(x, y+h, h)+dfs(x+h, y, h)+dfs(x+h, y+h, h)+')'
        return t
    print(dfs(0, 0, n))
if __name__ == '__main__':
    main()