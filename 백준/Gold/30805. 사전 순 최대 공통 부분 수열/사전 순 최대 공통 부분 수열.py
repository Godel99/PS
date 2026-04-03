import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    *a, = map(int, input().split())
    m = int(input())
    *b, = map(int, input().split())
    maxl = 0
    if s := set(a) & set(b): maxl = max(s)
    acur = bcur = 0
    ans = []
    for x in range(maxl, 0, -1):
        while True:
            if x in a[acur:] and x in b[bcur:]:
                anxt = a.index(x, acur)
                bnxt = b.index(x, bcur)
                ans.append(x)
                acur = anxt+1
                bcur = bnxt+1
            else: break
    print(len(ans))
    if ans: print(*ans)
    return  
if __name__ == '__main__':
    main()