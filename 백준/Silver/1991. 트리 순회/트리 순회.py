import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

def main():
    n = int(input())
    tree = {}
    for _ in range(n):
        a, b, c = input().split()
        tree[a] = [b, c]
    def preorder(node):
        if node == '.': return
        print(node, end='')
        preorder(tree[node][0])
        preorder(tree[node][1])
    def inorder(node):
        if node == '.': return
        inorder(tree[node][0])
        print(node, end='')
        inorder(tree[node][1])
    def postorder(node):
        if node == '.': return
        postorder(tree[node][0])
        postorder(tree[node][1])
        print(node, end='')
    preorder('A'); print()
    inorder('A'); print()
    postorder('A')
if __name__ == '__main__':
    main()