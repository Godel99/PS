import sys

input=sys.stdin.readline

def main():
    n, m = map(int, input().split())

    pattern_map = {}
    
    for _ in range(n):
        tokens = input().split()

        if len(tokens)<5:
            continue
        title = tokens[1]
        pattern = (tokens[2], tokens[3], tokens[4])

        if pattern in pattern_map:
            pattern_map[pattern][0] += 1
            pattern_map[pattern][1] = title
        else:
            pattern_map[pattern] = [1, title]
        
    out_line=[]

    for _ in range(m):
        tokens = input().split()
        notes = tuple(tokens)

        sing = pattern_map.get(notes)

        if sing is None:
            out_line.append('!')
        else:
            count, title = sing
            if count == 1:
                out_line.append(title)
            else:
                out_line.append('?')
    
    sys.stdout.write('\n'.join(out_line))

if __name__ == '__main__':
    main()