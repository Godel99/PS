import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    n, k = map(int, input().split())
    if n == k: print(0); return
    maxl = max(n, k)+2
    dp = [-1]*maxl
    dp[n] = 0
    dq = deque([n])
    while dq:
        cur = dq.popleft()
        nxt = cur*2
        if 0 <= nxt < maxl and dp[nxt] == -1:
            dp[nxt] = dp[cur]
            dq.appendleft(nxt)
        for nxt in [cur-1, cur+1]:
            if 0 <= nxt < maxl and dp[nxt] == -1:
                dp[nxt] = dp[cur]+1
                dq.append(nxt)
    print(dp[k])
    return
if __name__ == '__main__':
    main()