import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    SIZE = 122333
    n = int(input())
    A, B, C, D = [0]*n, [0]*n, [0]*n, [0]*n
    for i in range(n): 
        A[i], B[i], C[i], D[i] = map(int, input().split())
        C[i] = -C[i]; D[i] = -D[i]
    A.sort(); B.sort(); C.sort(); D.sort()
    AB = CD = cnt = ans = 0 
    LM = min(A[0]+B[0], C[0]+D[0])+SIZE-1
    NB, ND = [0]*n, [0]*n
    RK, RS = [0]*SIZE, [0]*SIZE
    while AB < n and CD < n:
        cnt += 1
        for i in range(AB, n):
            l = LM - A[i]
            while NB[i] < n:
                s = l-B[NB[i]]
                if s < 0: break
                if RK[s] == cnt: RS[s] += 1
                else: RK[s] = cnt; RS[s] = 1
                NB[i] += 1
                if NB[i] == n: AB += 1
        for i in range(CD, n):
            l = LM-C[i]
            while ND[i] < n:
                s = l-D[ND[i]]
                if s < 0: break
                if RK[s] == cnt: ans += RS[s]
                ND[i] += 1
                if ND[i] == n: CD += 1
        LM += SIZE
    print(ans)
    return
if __name__ == "__main__":
    main()