def solution(enroll, referral, seller, amount):
    result = dict.fromkeys(enroll, 0)

    parent = dict()

    for e, r in zip(enroll, referral):
        parent[e] = r

    for s, a in zip(seller, amount):
        cur = s
        profit = a * 100

        while cur != '-' and profit > 0:
            give = profit // 10
            result[cur] += profit - give
            cur = parent[cur]
            profit = give

    return list(result.values())


# def solution(enroll, referral, seller, amount):
#     result = dict.fromkeys(enroll, 0)

#     parent = dict()

#     for i, v in enumerate(enroll):
#         parent[v] = referral[i]

 
#     for i, v in enumerate(seller):
#         cur = v
#         profit = amount[i] * 100

#         while cur != '-' and profit > 0:
#             give = profit // 10
#             result[cur] += profit - give
#             cur = parent[cur]
#             profit = give

#     return list(result.values())