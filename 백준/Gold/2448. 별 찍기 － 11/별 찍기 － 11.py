import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    def tree_star(n):
        if n == 3: return ('  *  ', ' * * ', '*****') 
        star = tree_star(n//2)
        top = [' '*(n//2)+s+' '*(n//2) for s in star]
        bot = [s+' '+s for s in star]
        return top+bot
    print('\n'.join(tree_star(n)))
    return
if __name__ == '__main__':
    main()