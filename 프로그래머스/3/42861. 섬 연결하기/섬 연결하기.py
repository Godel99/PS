def solution(n, costs):
    costs_sorted = sorted(costs, key=lambda x: x[2])
    parent = [i for i in range(n)]

    def find(parent, x):
        if parent[x] != x:
            parent[x] = find(parent, parent[x])
        return parent[x]

    def union(parent, x, y):
        rootx = find(parent, x)
        rooty = find(parent, y)

        if rootx == rooty:
            return False

        if rootx > rooty:
            parent[rootx] = rooty
        else:
            parent[rooty] = rootx

        return True
    
    total_cost = 0
    for a, b, cost in costs_sorted:
        if union(parent, a, b):
            total_cost += cost

    return total_cost