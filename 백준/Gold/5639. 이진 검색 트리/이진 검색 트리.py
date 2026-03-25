import sys 
print = lambda *args, sep=" ", end="\n": sys.stdout.write(sep.join(map(str, args)) + end)
input = lambda: sys.stdin.readline().rstrip('\r\n')

sys.setrecursionlimit(20000)

def main():
    nums = list(map(int, sys.stdin.read().split()))
    ans = []
    def postorder(start, end):
        if start >= end: return
        root = nums[start]
        low, high= start+1, end
        while low < high:
            mid = (low+high)>>1
            if nums[mid] <= root: low = mid+1
            else: high = mid
        postorder(start+1, low)
        postorder(low, end)
        ans.append(str(root))
    postorder(0, len(nums))
    print('\n'.join(ans))
    return
if __name__ == '__main__':
    main()