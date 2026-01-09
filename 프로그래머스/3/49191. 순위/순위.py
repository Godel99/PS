import sys
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)
def input():
    return sys.stdin.readline().rstrip()

from collections import deque

def solution(n, results):
    graph = [[] for _ in range(n)]
    r_graph = [[] for _ in range(n)]

    for a, b in results:
        a -= 1; b -= 1
        graph[a].append(b)
        r_graph[b].append(a)

    def BFS(start, g):
        visited = [False] * n
        q = deque([start])
        visited[start] = True
        cnt = 0

        while q:
            cur = q.popleft()
            for nxt in g[cur]:
                if not visited[nxt]:
                    visited[nxt] = True
                    q.append(nxt)
                    cnt += 1

        return cnt
    ans = 0
    for i in range(n):
        win = BFS(i, graph)
        loss = BFS(i, r_graph)

        if win + loss == n - 1:
            ans += 1

    return ans
def main():
    print(solution(5,	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
if __name__ == '__main__':
    main()

# def solution(n, results):
#     win = [[False] * n for _ in range(n)]
#     for i, j in results:
#         win[i-1][j-1] = True
#     for k in range(n):
#         for i in range(n):
#             for j in range(n):
#                 if win[i][k] and win[k][j]:
#                     win[i][j] = True
#     cnt = 0
#     for i in range(n):
#         w = 0; l = 0
#         for j in range(n):
#             w += win[i][j]
#             l += win[j][i]
#         if w + l == n - 1:
#             cnt += 1
#     return cnt