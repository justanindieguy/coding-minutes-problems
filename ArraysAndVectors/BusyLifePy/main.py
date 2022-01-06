def busy_life(activities):
    activities.sort(key=lambda x: x[1])

    n = len(activities)
    endingTime = activities[0][1]
    ans = 1
    for i in range(1, n):
        startTime = activities[i][0]
        if endingTime <= startTime:
            endingTime = activities[i][1]
            ans += 1

    return ans


def main():
    activities = [(7, 9), (0, 10), (4, 5), (8, 9), (4, 10), (5, 7)]
    print(busy_life(activities))


if __name__ == "__main__":
    main()
