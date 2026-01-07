import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def SA(s):
    n = len(s); m = max(n, 1024)+1
    sa = list(range(n)); nr = [0] * (2*n); idx = [0] * n
    r = [0] * (2*n)
    for i in range(n):
        r[i] = int(s[i]) + 1

    d = 1
    while d < n:
        cmp = lambda i, j: (
            r[i] < r[j] or (r[i] == r[j] and r[i+d] < r[j+d])
        )
        cnt = [0] * m
        for i in range(n): 
            val = r[i+d] if i+d < n else 0
            cnt[val] += 1
        for i in range(1, m): cnt[i] += cnt[i-1]
        for i in range(n-1, -1, -1): 
            val = r[i+d] if i+d < n else 0
            cnt[val] -= 1
            idx[cnt[val]] = i
        cnt = [0] * m
        for i in range(n): cnt[r[i]] += 1
        for i in range(1, m): cnt[i] += cnt[i-1]
        for i in range(n-1, -1, -1): 
            cnt[r[idx[i]]] -= 1
            sa[cnt[r[idx[i]]]] = idx[i]
        nr[sa[0]] = 1
        for i in range(1, n): nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i])
        for i in range(n): r[i] = nr[i]
        d <<= 1
    global rev, ret
    rev = [0] * (n//2); ret = [0] * (n//2); ii = 0
    for i in sa:
        if i < n//2:
            rev[i] = ii
            ret[ii] = i; ii +=1

def main():
    n, k = map(int, input().split())
    s = input(); s = s + s
    if(n==k):
        ans = 0
        for i in range(n): ans = max(ans, int(s[i]))
        return print(ans)
    SA(s)
    l = 0; r = n
    while l < r:
        mid = l+r>>1
        flag = False
        for x in range((n-1)//k+1):
            cnt = 0; now = x
            while now < x+n:
                if rev[now%n] <= rev[ret[mid]]: now += 1
                now += (n-1)//k
                cnt += 1
            if cnt <= k:
                flag = True
                break

        if flag: r = mid
        else: l = mid + 1
    print(s[ret[l]: ret[l]+(n-1)//k+1])
if __name__ == '__main__':
    main()

