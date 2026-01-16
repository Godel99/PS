import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    p = []
    for i in range(n): p.append(list(map(int, input().split())))
    def f(x, y, s):
        t = p[x][y]
        for i in range(x, x+s):
            for j in range(y, y+s):
                if p[i][j] != t:
                    h = s // 2
                    w1, b1 = f(x, y, h) 
                    w2, b2 =f(x, y+h, h)
                    w3, b3 =f(x+h, y, h)
                    w4, b4 =f(x+h, y+h, h)
                    return (w1+w2+w3+w4, b1+b2+b3+b4)       
        if t: return (0, 1)
        else: return (1, 0)
    w, b = f(0, 0, n)
    print(w); print(b)
if __name__ == '__main__':
    main()