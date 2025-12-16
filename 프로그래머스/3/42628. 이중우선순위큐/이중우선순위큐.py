import heapq

def solution(operations):
    answer = DEPQ(operations)
    return answer

def DEPQ(operations):
    min_heap=[]
    max_heap=[]
    visited= {}
    idx=0

    for op in operations:
        command, val = op.split()
        val = int(val)

        if command == 'I':  # 입력
            heapq.heappush(min_heap, (val, idx))
            heapq.heappush(max_heap, (-val, idx))
            visited[idx]=True
            idx+=1
        else:
            if int(val)>0:  # 제거
                # 혹시 모를 쓰레기 값 제거
                while max_heap and not visited[max_heap[0][1]]:    
                    heapq.heappop(max_heap)
                if max_heap:
                    _, i = heapq.heappop(max_heap)  # 실제 제거
                    visited[i]=False
            else:
                # 혹시 모를 쓰레기 값 제거
                while min_heap and not visited[min_heap[0][1]]:    
                    heapq.heappop(min_heap)
                if min_heap:
                    _, i = heapq.heappop(min_heap)
                    visited[i]=False
    # 힙 동기화
    while max_heap and not visited[max_heap[0][1]]:    
        heapq.heappop(max_heap)
    while min_heap and not visited[min_heap[0][1]]:   
        heapq.heappop(min_heap)
    
    if not max_heap or not min_heap:
        return [0,0]
    else:
        return [-max_heap[0][0], min_heap[0][0]]

print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))

# def solution(operations):
#     answer = solution_(operations)
#     return answer

# def double_order_queue(operations):
#     stacks=[]
#     for op in operations:
#         order, val = op.split()
#         if order=='I':
#             stacks.append(int(val))
#         else:
#             if not stacks:
#                 continue
#             if int(val)>0:
#                 stacks.pop(stacks.index(max(stacks)))
#             else:
#                 stacks.pop(stacks.index(min(stacks)))
    
#     if stacks:
#         return max(stacks), min(stacks)
#     else:
#         return [0,0]