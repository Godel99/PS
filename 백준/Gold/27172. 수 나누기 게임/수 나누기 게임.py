import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)

def main():
    n = int(input())
    card = [*map(int, input().split())]
    score = [0]*n
    maxv = max(card)
    loc = [-1]*(maxv+1)
    for i, v in enumerate(card): loc[v] = i
    for i, v in enumerate(card):
        for j in range(v*2, maxv+1, v):
            if loc[j] != -1:
                score[i] += 1
                score[loc[j]] -= 1
    print(*score)
    return
if __name__ == "__main__":
    main()