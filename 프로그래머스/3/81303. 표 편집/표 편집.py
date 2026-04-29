def solution(n, k, cmd):
    ans, pre, nxt, st = ['O']*n, [-1]*n, [-1]*n, []
    for i in range(n): pre[i], nxt[i] = i-1, i+1
    nxt[-1] = -1
    for c in cmd:    
        if c[0] == 'D': 
            v = int(c.split()[1])
            for _ in range(v): k = nxt[k]
        elif c[0] == 'U':
            v = int(c.split()[1])
            for _ in range(v): k = pre[k]
        elif c[0] == 'C':
            st.append((pre[k], k, nxt[k]))
            if pre[k] != -1: nxt[pre[k]] = nxt[k]
            if nxt[k] != -1: pre[nxt[k]] = pre[k]
            if nxt[k] == -1: k = pre[k]
            else: k = nxt[k]
        else:
            pi, cur, ni = st.pop()
            if pi != -1: nxt[pi] = cur
            if ni != -1: pre[ni] = cur
    for _, cur, _ in st: ans[cur] = 'X'
    return ''.join(ans)