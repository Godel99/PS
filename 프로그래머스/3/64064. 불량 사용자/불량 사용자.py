def solution(user_id, banned_id):
    cnt_list = set()
    user_idx = [[] for _ in range(len(banned_id))]


    for b_idx, ban_id in enumerate(banned_id):
        if ban_id.count('*') == len(ban_id):
            for idx, u_id in enumerate(user_id):
                if len(u_id) == len(ban_id):
                    user_idx[b_idx].append(idx)

            continue

        for idx, u_id in enumerate(user_id):
            if len(u_id) != len(ban_id):
                continue
            for i in range(len(u_id)):
                if ban_id[i] == '*':
                    continue
                if u_id[i] != ban_id[i]:
                    break   
            else:
                user_idx[b_idx].append(idx)

    total_case = []
    
    def DFS(depth, set_f, user_idx, total_case):
        if depth == len(user_idx):
            return total_case.append(set_f.copy())

        for u_i in user_idx[depth]:
            if u_i not in set_f:
                set_f.add(u_i)
                DFS(depth+1, set_f, user_idx, total_case)
                set_f.remove(u_i)

    DFS(0, set(), user_idx, total_case)

    for case in total_case:
        cnt_list.add(tuple(case))

    return len(cnt_list)