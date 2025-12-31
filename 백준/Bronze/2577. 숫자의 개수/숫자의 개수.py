from collections import defaultdict

def main():
    A = int(input())
    B = int(input())
    C = int(input())

    result = str(A*B*C)

    num = defaultdict(int)

    for i in range(10):
        num[i] = 0

    for v in result:
        num[int(v)] += 1

    for i in num:
        print(num[i])

if __name__ == '__main__':
    main()
