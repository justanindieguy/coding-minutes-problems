def count_minimum_swaps(arr):
    n = len(arr)
    sorted_pairs = []
    for i in range(n):
        sorted_pairs.append((arr[i], i))

    sorted_pairs.sort()

    ans = 0
    visited = [False] * n
    for i in range(n):
        old_position = sorted_pairs[i][1]
        if visited[i] or old_position == i:
            continue

        node = i
        cycle = 0
        while not visited[node]:
            visited[node] = True
            next_node = sorted_pairs[node][1]
            node = next_node
            cycle += 1

        ans += cycle - 1

    return ans


def main():
    arr = [2, 4, 5, 1, 3]
    print(count_minimum_swaps(arr))


if __name__ == "__main__":
    main()
