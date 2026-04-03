import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    a = sorted(((int(v), i) for i, v in enumerate(input().split())), key=lambda x: (-x[0], x[1]))
    m = int(input())
    b = sorted(((int(v), i) for i, v in enumerate(input().split())), key=lambda x: (-x[0], x[1]))
    lia = lib = -1
    pa = pb = 0
    ans = []
    while pa < n and pb < m:
        va, ia = a[pa]
        vb, ib = b[pb]
        if va == vb:
            if ia > lia and ib > lib:
                ans.append(va)
                lia, lib = ia, ib
                pa += 1; pb += 1
            else:
                if ia <= lia: pa +=1
                else: pb += 1
        elif va > vb: pa += 1
        else: pb += 1
    print(len(ans))
    print(*ans)
    return  
if __name__ == '__main__':
    main()