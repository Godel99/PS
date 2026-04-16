import sys

def solve():
    MOD = 1_000_000_007
    data = sys.stdin.buffer.read().split()
    N = int(data[0])
    H = list(map(int, data[1:N+1]))

    left_child = [-1] * N
    right_child = [-1] * N
    parent = [-1] * N

    # 최대 힙 카르테시안 트리 구성 (스택 이용)
    stack = []
    for i in range(N):
        last_popped = -1
        while stack and H[stack[-1]] < H[i]:
            last_popped = stack.pop()
        if last_popped != -1:
            left_child[i] = last_popped
            parent[last_popped] = i
        if stack:
            right_child[stack[-1]] = i
            parent[i] = stack[-1]
        stack.append(i)

    root = stack[0]

    # 서브트리 크기 계산 (후위 순회)
    subtree_size = [1] * N
    stk = [(root, False)]
    while stk:
        node, done = stk.pop()
        if done:
            if parent[node] != -1:
                subtree_size[parent[node]] += subtree_size[node]
        else:
            stk.append((node, True))
            if right_child[node] != -1:
                stk.append((right_child[node], False))
            if left_child[node] != -1:
                stk.append((left_child[node], False))

    # 각 간선의 기여도 합산
    ans = 0
    for i in range(N):
        if parent[i] != -1:
            p = parent[i]
            diff = H[p] - H[i]
            cost = (diff * diff) % MOD
            s = subtree_size[i]
            ans = (ans + cost * s % MOD * (N - s)) % MOD

    print(ans)

solve()