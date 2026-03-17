import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        score = [list(map(int, input().split())) for _ in range(2)]
        if n == 1:
            print(max(score[0][0], score[1][0]))
            continue
        score[0][1] += score[1][0]
        score[1][1] += score[0][0]
        for i in range(2, n):
            score[0][i] += max(score[1][i-1], score[1][i-2])
            score[1][i] += max(score[0][i-1], score[0][i-2])
        print(max(score[0][-1], score[1][-1]))
if __name__ == '__main__':
    main()