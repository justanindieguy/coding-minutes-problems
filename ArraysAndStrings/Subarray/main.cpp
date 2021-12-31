#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
        return x > arr[1];
    if (i == arr.size() - 1)
        return x < arr[i - 1];
    return x > arr[i + 1] || x < arr[i - 1];
}

vector<int> subarraySortOptimal(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    // Find the right index where smallest and largest lie (subarray) for our solution
    if (smallest == INT_MAX)
        return {-1, -1};

    int left = 0;
    while (smallest >= arr[left])
        left++;

    int right = arr.size() - 1;
    while (largest <= arr[right])
        right--;

    return {left, right};
}

vector<int> subarraySortMySolution(vector<int> arr)
{
    int n = arr.size();

    int i = 0;
    int start = -1;
    int end = -1;
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            start = i;

            int j = i + 1;
            while (arr[j] < arr[i])
            {
                end = j;
                j++;
            }

            i = end + 1;
        }
        else
        {
            i++;
        }
    }

    if (start == -1)
        return {-1, -1};

    return {start, end};
}

vector<int> subarraySort(vector<int> arrA)
{
    vector<int> arrB(arrA);
    sort(arrA.begin(), arrA.end());

    int i = 0;
    int n = arrA.size();
    while (i < n && arrA[i] == arrB[i])
        i++;

    int j = arrA.size() - 1;
    while (j >= 0 && arrA[j] == arrB[j])
        j--;

    if (i == arrA.size())
        return {-1, -1};

    return {i, j};
}

int main()
{
    vector<int> arr{1, 2, 3, 8, 7, 5, 6, 4, 9, 10};
    vector<int> sortedArr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = subarraySortMySolution(arr);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
