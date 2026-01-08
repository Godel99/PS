import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def solution(scores):
    sorted_scores = sorted(scores, key = lambda x: (-x[0], x[1]))
    wanho = tuple(scores[0])
    wanho_sum = sum(wanho)
    maxs = -1
    rank = 1
    for f, s in sorted_scores:
        if s < maxs:
            if (f, s) == wanho:
                return -1
            continue

        maxs = s
        
        if f + s > wanho_sum:
            rank += 1

    return rank

def main():
    print(solution([[2,2],[1,4],[3,2],[3,2],[2,1]]))
if __name__ == '__main__':
    main()

