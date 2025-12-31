import sys

def main():
    max_value = idx = 0

    for i in range(9):
        v = int(input())
        if max_value < v:
            max_value = v
            idx = i + 1

    print(max_value)
    print(idx)
    
if __name__ == '__main__':
    main()
