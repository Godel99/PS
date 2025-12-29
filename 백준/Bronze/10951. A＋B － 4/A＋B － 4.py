import sys

def main():
    for line in sys.stdin:
        # 합계를 구함과 동시에 바로 출력
        a, b = map(int, line.split())
        sys.stdout.write(str(a + b) + '\n')

if __name__ == '__main__':
    main()