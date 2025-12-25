import sys

input=sys.stdin.readline

def main():
    n = int(input())
    note = input().strip()

    x = y = d = 0
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]

    visited = {(0, 0)}

    for c in note:
        if c == 'R':
            d = (d + 1) % 4
        elif c == 'L':
            d = (d + 3) % 4
        else:
            x += dx[d]; y += dy[d]
            visited.add((x, y))


    xs, ys = zip(*visited)
    minx, maxx = min(xs), max(xs)
    miny, maxy = min(ys), max(ys)

    maze = [['#'] * (maxy - miny + 1) for _ in range(maxx - minx + 1)]

    for x, y in visited:
        maze[x-minx][y-miny] = '.'
    
    for row in maze[::-1]:
        sys.stdout.write(''.join(row)+'\n')

if __name__ == '__main__':
    main()