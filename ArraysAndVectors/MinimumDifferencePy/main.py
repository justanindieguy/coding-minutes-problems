def get_minimum_pair_my_solution(arr1, arr2):
    pairs = []

    for num in arr1:
        pairs.append((num, 1))

    for num in arr2:
        pairs.append((num, 2))

    pairs.sort()

    i = 0
    n = len(pairs)
    minimum_diff = float("inf")
    minimum_pair = ()
    while i < n - 1:
        [num, origin_arr] = pairs[i]
        [next_num, next_origin_arr] = pairs[i + 1]

        if origin_arr != next_origin_arr:
            current_diff = abs(num - next_num)

            if current_diff < minimum_diff:
                minimum_pair = (num, next_num)
                minimum_diff = current_diff

        i += 1

    return minimum_pair


def get_minimum_pair_sort_sets(arr1, arr2):
    all_values = arr1 + arr2
    arr1_values = set(arr1)
    arr2_values = set(arr2)

    all_values.sort()

    n = len(all_values)
    minimum_pair = ()
    minimum_diff = float("inf")
    for i in range(n - 1):
        curr_value = all_values[i]
        next_value = all_values[i + 1]

        if curr_value in arr1_values and next_value in arr2_values:
            curr_diff = abs(curr_value - next_value)

            if curr_diff < minimum_diff:
                minimum_diff = curr_diff
                minimum_pair = (curr_value, next_value)

    return minimum_pair


def get_minimum_pair_sort(arr1, arr2):
    n = len(arr1)
    m = len(arr2)

    arr1.sort()
    arr2.sort()

    i = 0
    j = 0
    minimum_diff = float("inf")
    minimum_pair = ()
    while i < n and j < m:
        current_diff = abs(arr1[i] - arr2[j])

        if current_diff < minimum_diff:
            minimum_diff = current_diff
            minimum_pair = (arr1[i], arr2[j])
        if arr1[i] < arr2[j]:
            i += 1
        else:
            j += 1

    return minimum_pair


def get_minimum_pair_bruteforce(arr1, arr2):
    pair = (-1, -1)
    minimum_diff = float("inf")
    for num_one in arr1:
        current_diff = 0

        for num_two in arr2:
            current_diff = abs(num_one - num_two)

            if current_diff < minimum_diff:
                pair = (num_one, num_two)
                minimum_diff = current_diff

    return pair


def main():
    arr1 = [23, 5, 10, 17, 30]
    arr2 = [26, 134, 135, 14, 19]
    print(get_minimum_pair_sort_sets(arr1, arr2))


if __name__ == "__main__":
    main()
