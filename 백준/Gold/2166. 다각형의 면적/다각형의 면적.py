import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    v = [list(map(int, input().split())) for _ in range(n)]
    v.append(v[0])
    sumv = 0
    for i in range(n): sumv += v[i][0]*v[i+1][1]-v[i+1][0]*v[i][1]
    print(round(abs(sumv)/2, 1))
    return
if __name__ == "__main__":
    main()