def get_triplets(arr, Sum):
    n = len(arr)
    result = []
    arr.sort()

    for i in range(n):
        j = i + 1
        k = n - 1

        while j < k:
            current_sum = arr[i]
            current_sum += arr[j]
            current_sum += arr[k]

            if current_sum == Sum:
                result.append([arr[i], arr[j], arr[k]])
                j += 1
                k -= 1
            elif current_sum > Sum:
                k -= 1
            else:
                j += 1

    return result


def main():
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 15]
    S = 18

    result = get_triplets(arr, S)
    for triplet in result:
        print(triplet)


if __name__ == "__main__":
    main()
