import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    t = int(input())
    for _ in range(t):
        n, m, w = map(int, input().split())
        edge = []
        for _ in range(m):
            s, e, t = map(int, input().split())
            edge.append((s, e, t))
            edge.append((e, s, t))
        for _ in range(w):
            s, e, t = map(int, input().split())
            edge.append((s, e, -t))
        dist = [0]*(n+1)
        ans = 0
        for i in range(1, n+1):
            chg = 0
            for s, e, t in edge:
                if dist[s] > dist[e]+t:
                    dist[s] = dist[e]+t
                    chg = 1
                    if i == n: ans = 1
            if not chg: break
        if ans: print('YES')
        else: print('NO')
    return  
if __name__ == '__main__':
    main()