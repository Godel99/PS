import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    s, t = input(), input()
    st = []
    for c in s:
        st.append(c)
        if c == t[-1] and len(st) >= len(t):
            if ''.join(st[-len(t):]) == t:
                for _ in range(len(t)): st.pop()
    print(''.join(st) if st else 'FRULA')
    return
if __name__ == '__main__':
    main()