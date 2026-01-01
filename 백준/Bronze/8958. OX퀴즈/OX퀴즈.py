import sys

def main():
    T = int(input())
    for _ in range(T):
        n = input()
        total = cnt = 0
        for c in n:
            if c == 'O':
                cnt += 1
                total += cnt
            else:
                cnt = 0
        sys.stdout.write(f'{total}\n')     

if __name__ == '__main__':
    main()
