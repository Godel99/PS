# def solution(n, works):
#     if sum(works) <= n:
#         return 0
    
#     total_sum = 0
#     import heapq

#     max_heap = [-x for x in works]
#     heapq.heapify(max_heap)

#     while n>0:
#         heapq.heappush(max_heap, heapq.heappop(max_heap)+1)
#         n-=1

#     while max_heap:
#         total_sum += (heapq.heappop(max_heap)**2)

#     return total_sum

import heapq

def solution(n, works):
    if sum(works) <= n:
        return 0

    heap = [-w for w in works]
    heapq.heapify(heap)

    for _ in range(n):
        w = heapq.heappop(heap)
        heapq.heappush(heap, w + 1)

    return sum(x * x for x in heap)