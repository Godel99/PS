import sys

def main():
    A = dict()
    for i in range(ord('a'), ord('z')+1):
        A[chr(i)] = -1
    s = input()

    for i, c in enumerate(s):
        if A[c] == -1:
            A[c] = i
    for i in A.values():
        sys.stdout.write(f'{i} ')

if __name__ == '__main__':
    main()
