import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n, m, q = map(int, input().split())
    p = list(map(int, input().split()))
    minR = [n+1]*(n+1)
    L = 0
    inc = dec = 1
    for R in range(1, n):
        if p[R] == p[R-1]: continue
        if p[R] > p[R-1]:
            if dec > 1: L = R-1
            dec = 1; inc += 1
            if inc > m:
                while p[L] == p[L+1]: L += 1
                if minR[L+1] > R+1: minR[L+1] = R+1
                L += 1
                inc -= 1
        else:
            if inc > 1: L = R-1
            inc = 1; dec += 1
            if dec > m:
                while p[L] == p[L+1]: L += 1
                if minR[L+1] > R+1: minR[L+1] = R+1
                L += 1
                dec -= 1
    for i in range(n-1, 0, -1): minR[i] = min(minR[i], minR[i+1])
    ans = []
    for _ in range(q):
        L, R = map(int, input().split())
        if minR[L] <= R: ans.append('nej')
        else: ans.append('ja')
    print('\n'.join(ans))
    return
if __name__ == '__main__':
    main()