import sys
from collections import defaultdict

input=sys.stdin.readline

def main():
    T = int(input())
    n = int(input())
    A = list(map(int, input().split()))
    m = int(input())
    B = list(map(int, input().split()))

    A_case = defaultdict(int)

    for i in range(n):
        s = 0
        for j in range(i, n):
            A_case[s+A[j]] += 1
            s += A[j]

    total_case = 0

    for i in range(m):
        s = 0
        for j in range(i, m):
            s += B[j]
            total_case += A_case[T-s]

    sys.stdout.write(str(total_case))

if __name__ == '__main__':
    main()