import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def update(i, n, v):
    while i <= n:
        ftree[i] += v
        i += i&-i

def kth(k, n):
    pos = 0
    bit = 1 << (n.bit_length()-1)
    while bit:
        pw = pos+bit
        if pw <= n and ftree[pw] < k:
            k -= ftree[pw]
            pos = pw
        bit >>= 1
    return pos + 1

def main():
    n, k = map(int, input().split())
    global ftree
    ftree = [0]*(n+1)
    cur = 0
    ans = []
    for i in range(1, n+1): update(i, n, 1)
    for i in range(n, 0, -1):
        cur = (cur+k-1)%i
        idx = kth(cur+1, n)
        ans.append(str(idx))
        update(idx, n, -1)
    print('<'+', '.join(ans)+'>')
    return 0
if __name__ == '__main__':
    sys.exit(main())