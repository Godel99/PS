from collections import deque

def solution(n, computers):
    answer = DFS_counts(n, computers)
    return answer

def how_deep_network(n, computers):
    node_index=[0 for _ in range(n)]
    stacks=[]
    cnt=1
    for idx, val in enumerate(node_index):
        if val != 0:
            continue
        else:
            if computers[idx].count(1)==1:
                node_index[idx]=cnt
                cnt+=1
                continue
            else:
                stacks.append(idx)
            while stacks:
                p=stacks.pop()
                for i in range(n):
                    if node_index[i]!=0:
                        continue
                    if p==i:
                        node_index[i]=cnt
                        continue
                    if computers[p][i]==1:
                        if i not in stacks:
                            stacks.append(i)
                            node_index[i]=cnt
            cnt+=1          
    return max(node_index)         

def DFS_counts(n, computers):
    visited = [False] * n
    nets=0
    
    for start in range(n):
        if not visited[start]:
            queue=deque([start])
            visited[start]=True
            
            while queue:
                nd = queue.popleft()
                for nxt in range(n):
                    if computers[nd][nxt]== 1 and not visited[nxt]:
                        visited[nxt]=True
                        queue.append(nxt)
            nets+=1
    return nets