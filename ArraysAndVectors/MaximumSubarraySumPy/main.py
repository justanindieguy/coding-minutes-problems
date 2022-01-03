import math


def max_subarray_sum_kadane(arr):
    n = len(arr)
    ans = 0
    curr_sum = 0
    for i in range(n):
        if curr_sum + arr[i] > 0:
            curr_sum += arr[i]
        else:
            curr_sum = 0

        ans = max(ans, curr_sum)

    return ans


def max_subarray_sum_recursion(arr):
    n = len(arr)
    if n == 1:
        return arr[0]

    m = math.floor(n / 2)
    left_mss = max_subarray_sum_recursion(arr[:m])
    right_mss = max_subarray_sum_recursion(arr[m:])

    left_sum = float("-inf")
    right_sum = float("-inf")

    subarray_sum = 0
    for i in range(m, n):
        subarray_sum += arr[i]
        right_sum = max(right_sum, subarray_sum)

    subarray_sum = 0
    for i in range(m - 1, -1, -1):
        subarray_sum += arr[i]
        left_sum = max(left_sum, subarray_sum)

    ans = max(left_mss, right_mss)
    return max(ans, left_sum + right_sum)


def max_subarray_sum(arr):
    n = len(arr)

    ans = float("-inf")
    for start_idx in range(n):
        subarray_sum = 0
        for subarray_size in range(1, n + 1):
            if start_idx + subarray_size > n:
                break

            subarray_sum += arr[start_idx + subarray_size - 1]
            ans = max(ans, subarray_sum)

    return ans


def max_subarray_sum_bruteforce(arr):
    n = len(arr)

    ans = float("-inf")
    subarray_sum = 0
    for i in range(n):
        for j in range(i, n):
            for k in range(i, j):
                subarray_sum += arr[k]

            ans = max(ans, subarray_sum)
            subarray_sum = 0

    return ans


def main():
    arr = [-1, 2, 3, 4, -2, 6, -8, 3]
    print(max_subarray_sum_kadane(arr))


if __name__ == "__main__":
    main()
