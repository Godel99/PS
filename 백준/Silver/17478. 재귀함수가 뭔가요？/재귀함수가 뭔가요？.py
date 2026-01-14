import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def rec(d, n):
    s = '____'*(n-d)
    print(f'{s}"재귀함수가 뭔가요?"')
    if d == 0:
        return print(f'''{s}"재귀함수는 자기 자신을 호출하는 함수라네"
{s}라고 답변하였지.''')
    print(f'''{s}"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
{s}마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
{s}그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."''')
    rec(d-1, n)
    print(f'''{s}라고 답변하였지.''')  
    
def main():
    n = int(input())
    print('''어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.''')
    rec(n, n)
if __name__ == '__main__':
    main()