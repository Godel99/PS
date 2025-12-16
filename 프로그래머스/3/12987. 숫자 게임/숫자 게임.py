# import heapq

# def solution(A, B):
#     heapq.heapify(A)
#     heapq.heapify(B)

#     cnt = 0


#     b = heapq.heappop(B)
#     if max(A) < b:
#         return len(B) + 1
    
#     a = heapq.heappop(A)
#     if max(B) < a:
#         return 0

#     while True:
#         if a > b:
#             b = heapq.heappop(B)
#         elif a == b:
#             if not B:
#                 break
#             a = heapq.heappop(A)
#             b = heapq.heappop(B)
#         else:
#             cnt += 1
#             if not B:
#                 break
#             a = heapq.heappop(A)
#             b = heapq.heappop(B)

#     return cnt
# 실패한 코드

def solution(A, B):
    A.sort()
    B.sort()

    a = b = 0
    win = 0

    while a < len(A) and b < len(B):
        if A[a] < B[b]:
            win += 1
            a += 1
            b += 1
        else:
            b += 1
    return win

