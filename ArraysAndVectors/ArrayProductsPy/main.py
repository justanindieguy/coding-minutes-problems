import math


def array_products_division(arr):
    products = []
    all_nums_product = 1

    for num in arr:
        all_nums_product *= num

    for num in arr:
        products.append(math.floor(all_nums_product / num))

    return products


def array_products_bruteforce(arr):
    n = len(arr)
    products = []

    for i in range(n):
        current_product = 1
        for j in range(n):
            if i == j:
                continue

            current_product *= arr[j]

        products.append(current_product)

    return products


def array_products_indices(arr):
    n = len(arr)
    products = []

    for base_idx in range(n):
        i = 0
        left_product = 1
        while i < base_idx:
            left_product *= arr[i]
            i += 1

        j = n - 1
        right_product = 1
        while j > base_idx:
            right_product *= arr[j]
            j -= 1

        products.append(left_product * right_product)

    return products


def array_products_optimal(arr):
    n = len(arr)
    products = [0] * n
    left_products = [0] * n
    right_products = [0] * n

    left_product = 1
    for i in range(n):
        left_product *= arr[i]
        left_products[i] = left_product

    right_product = 1
    for i in range(n - 1, -1, -1):
        right_product *= arr[i]
        right_products[i] = right_product

    for i in range(n):
        if i == 0:
            products[i] = right_products[1]
        elif i == n - 1:
            products[i] = left_products[n - 2]
        else:
            products[i] = left_products[i - 1] * right_products[i + 1]

    return products


def main():
    arr = [1, 2, 3, 4, 5]
    print(array_products_optimal(arr))


if __name__ == "__main__":
    main()
