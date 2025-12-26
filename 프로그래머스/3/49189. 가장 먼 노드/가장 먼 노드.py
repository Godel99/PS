from collections import defaultdict, deque

def solution(n, edge):
    edges = defaultdict(list)
    for a,b in edge:
        edges[a].append(b)
        edges[b].append(a)

    distance = [-1] * (n + 1)
    distance[1] = 0
    queue = deque([1])

    while queue:
        nd = queue.popleft()
        for e in edges[nd]:
            if distance[e] == -1:
                queue.append(e)
                distance[e] = distance[nd] + 1

    max_distance = max(distance)

    return distance.count(max_distance)