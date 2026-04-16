import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    MOD = 1_000_000_007
    n = int(input())
    h = [*map(int, input().split())]
    ch = [1]*n
    st = []
    ans = 0
    for r in range(n):
        while st and h[st[-1]] <= h[r]:
            l = st.pop()
            m = st[-1] if st and h[st[-1]] < h[r] else r
            dif = h[m]-h[l]
            way = (n-ch[l])*ch[l]%MOD
            cst = dif*dif%MOD
            ans = (ans+way*cst)%MOD
            ch[m] += ch[l]
        st.append(r)
    while len(st) > 1:
        r = st.pop()
        l = st[-1] 
        dif = h[l]-h[r]
        way = (n-ch[r])*ch[r]%MOD
        cst = dif*dif%MOD
        ans = (ans+way*cst)%MOD
        ch[l] += ch[r]
    print(ans)   
    return
if __name__ == "__main__":
    main()