import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

from collections import deque

def main():
    n, k = map(int, input().split())
    if n == k: print(0); return
    maxl = (n if n > k else k)+2
    dp = [float('inf')]*maxl
    dp[n] = 0
    dq = deque([n])
    while dq:
        cur = dq.popleft()
        for nxt, sec in [(cur-1, 1), (cur+1, 1), (cur*2, 0)]:
            if 0 <= nxt < maxl and dp[nxt] > dp[cur]+sec:
                dp[nxt] = dp[cur]+sec   
                if sec: dq.append(nxt)
                else: dq.appendleft(nxt)
    print(dp[k])
    return
if __name__ == '__main__':
    main()