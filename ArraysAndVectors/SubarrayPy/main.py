def outOfOrder(arr, i):
    x = arr[i]
    if i == 0:
        return x > arr[i]
    if i == len(arr) - 1:
        return x < arr[i - 1]
    return x > arr[i + 1] or x < arr[i - 1]


def subarray_sort_optimal(arr):
    smallest = float("inf")
    largest = float("-inf")

    n = len(arr)
    for i in range(n):
        x = arr[i]
        if outOfOrder(arr, i):
            smallest = min(smallest, x)
            largest = max(largest, x)

    if smallest == float("inf"):
        return [-1, -1]

    left = 0
    while smallest >= arr[left]:
        left += 1

    right = n - 1
    while largest <= arr[right]:
        right -= 1

    return [left, right]


def subarray_sort(arr_a):
    arr_b = arr_a.copy()
    arr_b.sort()

    i = 0
    n = len(arr_a)
    while i < n and arr_a[i] == arr_b[i]:
        i += 1

    j = len(arr_b) - 1
    while j >= 0 and arr_a[j] == arr_b[j]:
        j -= 1

    if i == len(arr_a):
        return [-1, -1]

    return [i, j]


def subarray_sort_my_solution(arr):
    n = len(arr)

    i = 0
    start = -1
    end = -1
    while i < n - 1:
        if arr[i] > arr[i + 1]:
            start = i
            j = i + 1

            while arr[j] < arr[i]:
                end = j
                j += 1

            i = end + 1
        else:
            i += 1

    if end == -1:
        return [-1, -1]

    return [start, end]


def main():
    arr = [1, 2, 3, 8, 7, 5, 6, 4, 9, 10]
    sorted_array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    print(subarray_sort_optimal(sorted_array))


if __name__ == "__main__":
    main()
