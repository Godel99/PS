import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    s = input()
    pri = {'*': 2, '/': 2, '+': 1, '-': 1, '(': 0}
    st = []
    ans = []
    for c in s:
        if 'A' <= c <= 'Z': ans.append(c)
        elif c == '(': st.append(c)
        elif c == ')':
            while st and st[-1] != '(': ans.append(st.pop())
            st.pop()
        else:
            while st and pri[st[-1]] >= pri[c]: ans.append(st.pop())
            st.append(c)
    while st: ans.append(st.pop())
    print(''.join(ans))
    return  
if __name__ == '__main__':
    main()