import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    c = int(input_data[0])

    # 1. 확률 증폭 및 2의 거듭제곱 매크로 정의
    macros = [
        "a=? max ?",
        "b=a max a",
        "c_m=b max b", # 'c'는 입력값 변수와 겹치지 않게 주의 (출력은 'c'로 유지)
        "d=c_m max c_m".replace("c_m", "c"),
        "e=d max d",
        "f=e max e",
        "g=f max f",
        "h=g max g",
        "i=h max h",
        "j=i max i",
        "k=j max j",
        "l=k max k",
        "m=l max l",  # m은 99.9999% 확률로 255
        "n=m / m",    # n = 1
        "o=n + n",    # o = 2
        "p=o + o",    # p = 4
        "q=p + p",    # q = 8
        "r=q + q",    # r = 16
        "s=r + r",    # s = 32
        "t=s + s",    # t = 64
        "u=t + t"     # u = 128
    ]

    # 매크로 문자열 내 임시 변수 처리 복구
    macros[2] = "c=b max b"
    macros[3] = "d=c max c"

    result = "\n".join(macros) + "\n"

    # 2. 목표 상수 조립
    if c == 0:
        result += "n - n\n"
    else:
        terms = []
        for i in range(8):
            if (c >> i) & 1:
                terms.append(chr(ord('n') + i))
        result += " + ".join(terms) + "\n"

    print(result)

if __name__ == '__main__':
    solve()