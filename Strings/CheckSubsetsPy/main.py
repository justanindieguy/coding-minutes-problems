def is_subset(s1, s2):
    i = len(s1) - 1
    j = len(s2) - 1

    while i >= 0 and j >= 0:
        if s2[j] == s1[i]:
            i -= 1
            j -= 1
        else:
            i -= 1

    if j == -1:
        return True

    return False


def main():
    s1 = input()
    s2 = input()
    print(is_subset(s1, s2))


if __name__ == "__main__":
    main()
