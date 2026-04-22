import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    a = [*map(int, input().split())]
    ans, cnt, head, nxt, pre = [0]*n, [0]*(n+1), [-1]*(n+1), [-1]*(n+1), [-1]*(n+1)
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
    while p2 < n and a[p2-1] == a[p2]: p2 += 1
    while idx < n and 2*mcnt-1 < size:
        while a[p1] == a[p2] or vis[p1]: p1 += 1
        vis[p1] = 1
        size -= 1
        Remove(cnt[a[p1]], a[p1])
        ans[idx] = p1+1; idx += 1
        if idx == n or 2*mcnt-1 == size: break
        while a[p1] == a[p2] or vis[p2]: p2 += 1
        vis[p2] = 1
        size -= 1
        Remove(cnt[a[p2]], a[p2])
        ans[idx] = p2+1; idx += 1
    maxv = head[mcnt]
    p1 = 0
    while p1 < vis[p1]: p1 += 1
    p2 = p1
    while(idx < n):
        while a[p1] != maxv or vis[p1]: p1 += 1
        vis[p1] = 1
        ans[idx] = p1+1; idx += 1
        if idx == n: break
        while a[p2] == maxv or vis[p2]: p2 += 1
        vis[p2] = 1
        ans[idx] = p2+1; idx += 1
    print(*ans)
    return
if __name__ == "__main__":
    main()