import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    a = [*map(int, input().split())]
    ans = [0]*n
    cnt, head, nxt, pre = [0]*(n+1), [-1]*(n+1), [-1]*(n+1), [-1]*(n+1)
    vis = bytearray(n)
    mcnt = 0
    for i in range(n): cnt[a[i]] += 1
    def Add(c, x):
        nxt[x] = head[c]
        if head[c] != -1: pre[head[c]] = x
        head[c] = x
    def Remove(c, x):
        nonlocal mcnt
        if pre[x] != -1: nxt[pre[x]] = nxt[x]
        else: head[c] = nxt[x]
        if nxt[x] != -1: pre[nxt[x]] = pre[x]
        pre[x] = nxt[x] = -1
        cnt[x] -= 1
        Add(cnt[x], x)
        if head[mcnt] == -1: mcnt -= 1
    for i in range(1, n+1):
        if cnt[i]:
            Add(cnt[i], i)
            if mcnt < cnt[i]: mcnt = cnt[i]
    if 2*mcnt-1 > n: print(-1); return
    idx, size = 0, n
    p1, p2 = 0, 1
    while p2 < n and a[p2-1] == a[p2]: p2 += 1   # 경계 체크
    while idx < n and 2*mcnt-1 < size:
        while p1 < n and (vis[p1] or (p2 < n and a[p1] == a[p2])): p1 += 1
        if p1 >= n: break
        vis[p1] = 1; size -= 1
        Remove(cnt[a[p1]], a[p1])
        ans[idx] = p1+1; idx += 1
        if idx == n or 2*mcnt-1 == size: break     # and → or
        while p2 < n and (vis[p2] or a[p2] == a[p1]): p2 += 1
        if p2 >= n: break
        vis[p2] = 1; size -= 1
        Remove(cnt[a[p2]], a[p2])
        ans[idx] = p2+1; idx += 1
    maxv = head[mcnt]
    p1 = 0
    while p1 < n and vis[p1]: p1 += 1
    p2 = p1
    while idx < n:
        while p1 < n and (vis[p1] or a[p1] != maxv): p1 += 1
        if p1 >= n: break
        vis[p1] = 1
        ans[idx] = p1+1; idx += 1
        if idx == n: break
        while p2 < n and (vis[p2] or a[p2] == maxv): p2 += 1
        if p2 >= n: break
        vis[p2] = 1
        ans[idx] = p2+1; idx += 1
    print(*ans)

if __name__ == "__main__":
    main()