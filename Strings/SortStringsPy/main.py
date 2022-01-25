"""
Sample Input
____________
3
92 022
82 12
77 13
2 false numeric

Sample Output
_____________
82 12
77 13
92 022
"""


def get_token_at(str, key):
    tokens = str.split()
    return tokens[int(key) - 1]


def main():
    n = int(input())

    rows = []
    for i in range(n):
        rows.append(input())

    params = input()
    key, reversal, ordering = params.split()

    # 1. Store strings with pairs.
    rowsWKeys = []
    for row in rows:
        rowsWKeys.append((row, get_token_at(row, key)))

    # 2. Sort
    if ordering == "numeric":
        rowsWKeys.sort(key=lambda row: int(row[1]))
    else:
        rowsWKeys.sort(key=lambda row: row[1])

    # Reversal
    if reversal == "true":
        rowsWKeys.reverse()

    for row in rowsWKeys:
        print(row[0])


if __name__ == "__main__":
    main()
