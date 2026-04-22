import sys
from collections import Counter, defaultdict

def main():
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    arr = list(map(int, data[1:n+1]))

    cnt = Counter(arr)
    buckets = defaultdict(set)  # count -> {value, ...}
    for v, c in cnt.items():
        buckets[c].add(v)

    max_cnt = max(cnt.values())

    if 2 * max_cnt - 1 > n:
        sys.stdout.write("-1\n")
        return

    def remove(v):
        nonlocal max_cnt
        c = cnt[v]
        buckets[c].discard(v)
        cnt[v] = c - 1
        if c - 1 > 0:
            buckets[c - 1].add(v)
        if not buckets[max_cnt]:
            max_cnt -= 1

    res = [0] * n
    vis = bytearray(n)
    i = 0
    unvis_size = n

    # ── Phase 1 ────────────────────────────────────────────────────
    if 2 * max_cnt - 1 < unvis_size:
        pos1 = 0
        pos2 = 1
        while pos2 < n and arr[pos2 - 1] == arr[pos2]:
            pos2 += 1

        while i < n and 2 * max_cnt - 1 < unvis_size:
            while pos1 < n and (vis[pos1] or (pos2 < n and arr[pos1] == arr[pos2])):
                pos1 += 1
            if pos1 >= n:
                break
            vis[pos1] = 1; unvis_size -= 1
            remove(arr[pos1])
            res[i] = pos1; i += 1

            if i == n or 2 * max_cnt - 1 == unvis_size:
                break

            while pos2 < n and (vis[pos2] or arr[pos2] == arr[pos1]):
                pos2 += 1
            if pos2 >= n:
                break
            vis[pos2] = 1; unvis_size -= 1
            remove(arr[pos2])
            res[i] = pos2; i += 1

    # ── Phase 2 ────────────────────────────────────────────────────
    max_val = next(iter(buckets[max_cnt]))  # head[max_cnt] 대체
    pos1 = 0
    while pos1 < n and vis[pos1]:
        pos1 += 1
    pos2 = pos1

    while i < n:
        while pos1 < n and (vis[pos1] or arr[pos1] != max_val):
            pos1 += 1
        if pos1 >= n:
            break
        vis[pos1] = 1
        res[i] = pos1; i += 1

        if i == n:
            break

        while pos2 < n and (vis[pos2] or arr[pos2] == max_val):
            pos2 += 1
        if pos2 >= n:
            break
        vis[pos2] = 1
        res[i] = pos2; i += 1

    sys.stdout.write(' '.join(map(str, (r + 1 for r in res))) + '\n')

main()