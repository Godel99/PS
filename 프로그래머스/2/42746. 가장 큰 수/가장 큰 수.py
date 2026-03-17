from functools import cmp_to_key

def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=cmp_to_key(lambda a, b: -1 if a+b > b+a else 1))
    ans = ''.join(numbers)
    return '0' if ans[0] == '0' else ans