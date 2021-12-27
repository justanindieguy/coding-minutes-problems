def longest_band(arr):
    longest_band_len = 0
    current_band_len = 1
    arr.sort()

    for i in range(len(arr) - 1):
        if arr[i] + 1 == arr[i + 1]:
            current_band_len += 1
        else:
            longest_band_len = max(longest_band_len, current_band_len)
            current_band_len = 1

    return longest_band_len


def longest_band_sets(arr):
    items = set(arr)
    already_checked = set()
    longest_band_len = 0
    current_band_len = 1

    i = 0
    while i < len(arr):
        current_number = arr[i]
        next_number = current_number + 1

        if current_number in already_checked:
            i += 1
            continue

        while next_number in items:
            already_checked.add(next_number)
            current_band_len += 1
            next_number += 1

        longest_band_len = max(longest_band_len, current_band_len)
        current_band_len = 1
        i += 1

    return longest_band_len


def main():
    arr = [1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6]
    result = longest_band_sets(arr)
    print(result)


if __name__ == "__main__":
    main()
