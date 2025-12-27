from collections import defaultdict, deque

def solution(n, roads, sources, destination):
    # 인접 리스트 구성
    graph = [[] for _ in range(n + 1)]
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)
    
    # 거리 배열 초기화
    dist = [-1] * (n + 1)
    dist[destination] = 0
    
    # BFS
    q = deque([destination])
    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            if dist[nxt] == -1:
                dist[nxt] = dist[cur] + 1
                q.append(nxt)
    
    # 결과 반환
    return [dist[s] for s in sources]

# def solution(n, roads, sources, destination):
#     graph = defaultdict(list)
#     for a, b in roads:
#         graph[a].append(b)
#         graph[b].append(a)
    
#     result = []

#     distance = [-1] * (n + 1)
#     distance[destination] = 0
#     q = deque([destination])

#     while q:
#         cur = q.popleft()
#         for g in graph[cur]:
#             if distance[g] == -1:
#                 q.append(g)
#                 distance[g] = distance[cur] + 1
    
#     for s in sources:
#         result.append(distance[s])
        
#     return result