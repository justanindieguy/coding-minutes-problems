def string_search(big, small):
    result = []
    index = big.find(small)

    while index != -1:
        result.append(index)
        index = big.find(small, index + 1)

    return result


def main():
    big_string = "I liked the movie, acting in movie was great!"
    small_string = "movie"
    occurrences = string_search(big_string, small_string)
    print(occurrences)


if __name__ == "__main__":
    main()
