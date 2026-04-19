import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    p = [0]+[*map(int, input().split())]
    e = [[] for _  in range(n+1)]
    s = [set() for _ in range(n+1)]
    v = [0]+[*map(int, input().split())]
    deg = [0]*(n+1)
    for i in range(1, n+1):
        if p[i] == -1: continue
        deg[p[i]] += 1
        e[p[i]].append(i)
    st = [i for i in range(1, n+1) if deg[i] == 0]
    ans = [0]*n
    while st:
        cur = st.pop()
        s[cur].add(v[cur])
        prv = 0
        for nxt in e[cur]: prv = max(prv, ans[nxt-1])
        for nv in range(prv, n+1):
            if nv not in s[cur]:
                ans[cur-1] = nv
                break
        if p[cur] == -1: continue
        if len(s[p[cur]]) >= len(s[cur]): s[p[cur]].update(s[cur])
        else:
            s[cur].update(s[p[cur]])
            s[p[cur]] = s[cur]
        deg[p[cur]] -= 1
        if deg[p[cur]] == 0: st.append(p[cur])
    print('\n'.join(map(str, ans)))
    return
if __name__ == "__main__":
    main()