import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

def josephus(n, k):
    if n == 1:
        return 0
    
    # 1. 내려가는 단계 (Downward): N이 1이 될 때까지의 경로를 저장
    path = []
    curr = n
    while curr > 1:
        path.append(curr)
        if curr < k:
            curr = curr - 1
        else:
            curr = curr - curr // k
            
    # 2. 올라가는 단계 (Upward): 1(Base case)부터 시작하여 역순으로 계산
    result = 0  # n=1일 때의 반환값
    
    # path 리스트를 뒤에서부터 순회 (스택 Pop과 동일)
    while path:
        curr_n = path.pop()
        
        if curr_n < k:
            # 재귀 코드의: return (josephus(n-1, k)+k)%n 부분
            result = (result + k) % curr_n
        else:
            # 재귀 코드의: l = ... 부분 로직
            # result는 재귀 호출의 결과값(l)에 해당함
            l = result - (curr_n % k)
            
            if l < 0:
                result = l + curr_n
            else:
                result = l + l // (k - 1)
                
    return result
def main():
    n, k = map(int, input().split())
    print(n) if k == 1 else print(josephus(n,k)+1)
if __name__ == '__main__':
    main()