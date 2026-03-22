import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    n, k = map(int, input().split())
    if n == k: print(0); print(1); return
    maxl = max(n, k)+2
    dp = [-1]*maxl
    dp[n] = 0
    dq = deque([n])
    cnt = 0
    while dq:
        cur = dq.popleft()
        if cur == k: 
            cnt += 1
            continue
        for nxt in [cur-1, cur+1, cur*2]:
            if 0 <= nxt < maxl and (dp[nxt] == -1 or dp[nxt] == dp[cur]+1):
                dp[nxt] = dp[cur]+1
                dq.append(nxt)
    print(dp[k])
    print(cnt)
    return
if __name__ == '__main__':
    main()