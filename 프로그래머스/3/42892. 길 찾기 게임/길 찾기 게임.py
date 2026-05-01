import sys
sys.setrecursionlimit(2000)

class Node:
    def __init__(self, id, x, y):
        self.id = id
        self.x = x
        self.y = y
        self.left = None
        self.right = None

def insert(p, c):
    if c.x < p.x:
        if p.left is None: p.left = c
        else: insert(p.left, c)
    else:
        if p.right is None: p.right = c
        else: insert(p.right, c)

def solution(nodeinfo):
    tmp, pre, post = [], [], []
    for i, info in enumerate(nodeinfo): tmp.append([info[0], info[1], i+1])
    tmp.sort(key=lambda x: (-x[1], x[0]))
    nodes = [Node(id=t[2], x=t[0], y=t[1]) for t in tmp]
    root = nodes[0]
    for i in range(1, len(nodes)): insert(root, nodes[i])
    def preorder(node):
        if node is None: return
        pre.append(node.id)
        preorder(node.left)
        preorder(node.right)
    def postorder(node):
        if node is None: return
        postorder(node.left)
        postorder(node.right)
        post.append(node.id)
    preorder(root)
    postorder(root)
    return [pre, post]
