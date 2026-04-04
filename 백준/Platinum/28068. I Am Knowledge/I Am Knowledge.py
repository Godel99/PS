import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    pb, mb = [], []
    for _ in range(n):
        a, b = map(int, input().split())
        if a <= b: pb.append((a, b))
        else: mb.append((b, a))
    pb.sort()
    mb.sort(reverse=True)
    joy = 0
    for a, b in pb:
        if a > joy: print(0); return
        joy += b-a
    for a, b in mb:
        if b > joy: print(0); return
        joy -= b-a
    print(1)
    return  
if __name__ == '__main__':
    main()