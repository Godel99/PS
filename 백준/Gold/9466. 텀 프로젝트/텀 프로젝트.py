import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = [0]+[*map(int, input().split())]
        deg = [0]*(n+1)
        for i in range(1, n+1): deg[s[i]] += 1
        st = [i for i in range(1, n+1) if deg[i] == 0]
        ans = 0
        while st:
            cur = st.pop() 
            ans += 1
            nxt = s[cur]
            deg[nxt] -= 1
            if deg[nxt] == 0: st.append(nxt)
        print(ans)  
    return
if __name__ == "__main__":
    main()