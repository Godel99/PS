import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    n, k = map(int, input().split())
    if n == k: print(0); print(n); return
    maxl = max(n, k)+2
    dp = [-1]*maxl
    par = [-1]*maxl
    dp[n] = 0
    dq = deque([n])
    while dq:
        cur = dq.popleft()
        if cur == k: 
            print(dp[cur])
            ans = []
            while cur != -1:
                ans.append(cur)
                cur = par[cur]
            print(*reversed(ans))
            return
        for nxt in [cur-1, cur+1, cur*2]:
            if 0 <= nxt < maxl and dp[nxt] == -1:
                dp[nxt] = dp[cur]+1
                dq.append(nxt)
                par[nxt] = cur
    return
if __name__ == '__main__':
    main()