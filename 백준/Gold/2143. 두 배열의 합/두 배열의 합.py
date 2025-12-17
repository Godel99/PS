import sys
from collections import defaultdict

input=sys.stdin.readline

def main():
    T = int(input())
    A_n = int(input())
    A = list(map(int, input().split()))
    B_n = int(input())
    B = list(map(int, input().split()))

    A_case = defaultdict(int)

    for i in range(A_n):
        sum_case = A[i]
        A_case[sum_case] += 1
        for j in range(i+1, A_n):
            A_case[sum_case+A[j]] += 1
            sum_case += A[j]

    total_case = 0

    for i in range(B_n):
        b_sum = B[i]
        total_case += A_case[T-b_sum]
        for j in range(i+1, B_n):
            b_sum += B[j]
            total_case += A_case[T-b_sum]


    sys.stdout.write(str(total_case))

if __name__ == '__main__':
    main()