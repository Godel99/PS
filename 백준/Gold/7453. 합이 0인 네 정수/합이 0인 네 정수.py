import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    A, B, C, D = [0]*n, [0]*n, [0]*n, [0]*n
    for i in range(n): A[i], B[i], C[i], D[i] = map(int, input().split())
    sAB, sCD = [0]*n*n, [0]*n*n
    idx = 0
    for i in range(n):
        for j in range(n):
            sAB[idx] = A[i]+B[j]
            sCD[idx] = C[i]+D[j]
            idx += 1
    sAB.sort()
    sCD.sort()
    ans = 0
    l, r = 0, len(sCD)-1
    while l < len(sAB) and r >= 0:
        vAB = sAB[l]
        vCD = sCD[r]
        if vAB+vCD > 0: r -= 1
        elif vAB+vCD < 0: l += 1
        else:
            cntAB = cntCD = 0
            while l < len(sAB) and sAB[l] == vAB:
                cntAB += 1
                l += 1
            while r >= 0 and sCD[r] == vCD:
                cntCD += 1
                r -= 1
            ans += cntAB*cntCD
    print(ans)
    return
if __name__ == "__main__":
    main()