def trapped_water_arrays(heights):
    n = len(heights)
    if n <= 2:
        return 0

    left = [0] * n
    right = [0] * n

    left[0] = heights[0]
    right[n - 1] = heights[n - 1]

    for i in range(1, n):
        left[i] = max(left[i - 1], heights[i])
        right[n - i - 1] = max(right[n - i], heights[n - i - 1])

    water = 0
    for i in range(n):
        water += min(left[i], right[i]) - heights[i]

    return water


def trapped_water(arr):
    total_water = 0

    for i in range(len(arr)):
        left = 0
        right = 0

        # Calculate largest height to the left (inclusive)
        j = i
        while j > -1:
            left = max(left, arr[j])
            j -= 1

        # Calculate largest height to the right (inclusive)
        j = i
        while j < len(arr):
            right = max(right, arr[j])
            j += 1

        total_water += min(left, right) - arr[i]

    return total_water


def main():
    arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(trapped_water_arrays(arr))


if __name__ == "__main__":
    main()
