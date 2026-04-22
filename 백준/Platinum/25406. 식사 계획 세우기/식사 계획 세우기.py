import sys
from array import array

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    n = int(data[idx]); idx += 1

    MAX_N = 300_001

    arr  = array('i', (int(data[idx + i]) for i in range(n))); idx += n
    res  = array('i', [0] * n)
    vis  = bytearray(n)

    cnt  = array('i', [0] * MAX_N)
    head = array('i', [-1] * MAX_N)
    nxt  = array('i', [-1] * MAX_N)
    prv  = array('i', [-1] * MAX_N)

    for i in range(n):
        cnt[arr[i]] += 1

    max_cnt = 0
    for v in range(1, n + 1):
        c = cnt[v]
        if c == 0:
            continue
        old = head[c]
        nxt[v] = old
        if old != -1:
            prv[old] = v
        head[c] = v
        if c > max_cnt:
            max_cnt = c

    if 2 * max_cnt - 1 > n:
        sys.stdout.write("-1\n")
        return

    _arr = arr; _res = res; _vis = vis
    _cnt = cnt; _head = head; _nxt = nxt; _prv = prv

    def remove(x):
        nonlocal max_cnt
        c = _cnt[x]
        px = _prv[x]; nx = _nxt[x]
        if px != -1: _nxt[px] = nx
        else:        _head[c] = nx
        if nx != -1: _prv[nx] = px
        _prv[x] = _nxt[x] = -1
        c -= 1; _cnt[x] = c
        old = _head[c]
        _nxt[x] = old
        if old != -1: _prv[old] = x
        _head[c] = x
        if _head[max_cnt] == -1:
            max_cnt -= 1

    i = 0
    unvis_size = n

    # ── Phase 1 ────────────────────────────────────────────────────
    if 2 * max_cnt - 1 < unvis_size:  # Phase 1이 필요한 경우에만 pos2 초기화
        pos1 = 0
        pos2 = 1
        # pos2 초기화: 경계 체크 추가
        while pos2 < n and _arr[pos2 - 1] == _arr[pos2]:
            pos2 += 1

        while i < n and 2 * max_cnt - 1 < unvis_size:
            # pos1 찾기: 경계 체크 추가
            while pos1 < n and (_vis[pos1] or (pos2 < n and _arr[pos1] == _arr[pos2])):
                pos1 += 1
            if pos1 >= n:
                break
            _vis[pos1] = 1; unvis_size -= 1
            remove(_arr[pos1])
            _res[i] = pos1; i += 1

            if i == n or 2 * max_cnt - 1 == unvis_size:
                break

            # pos2 찾기: 경계 체크 추가
            while pos2 < n and (_vis[pos2] or _arr[pos2] == _arr[pos1]):
                pos2 += 1
            if pos2 >= n:
                break
            _vis[pos2] = 1; unvis_size -= 1
            remove(_arr[pos2])
            _res[i] = pos2; i += 1

    # ── Phase 2 ────────────────────────────────────────────────────
    max_val = _head[max_cnt]
    pos1 = 0
    while pos1 < n and _vis[pos1]:
        pos1 += 1
    pos2 = pos1

    while i < n:
        while pos1 < n and (_vis[pos1] or _arr[pos1] != max_val):
            pos1 += 1
        if pos1 >= n:
            break
        _vis[pos1] = 1
        _res[i] = pos1; i += 1

        if i == n:
            break

        while pos2 < n and (_vis[pos2] or _arr[pos2] == max_val):
            pos2 += 1
        if pos2 >= n:
            break
        _vis[pos2] = 1
        _res[i] = pos2; i += 1

    sys.stdout.write(' '.join(str(_res[j] + 1) for j in range(n)) + '\n')

main()