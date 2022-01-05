#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <limits.h>
using namespace std;

pair<int, int> minimumDifferenceMySolution(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<pair<int, int>> pairs(n + m);

    for (int i = 0; i < n; i++)
    {
        pairs[i].first = arr1[i];
        pairs[i].second = 1;
    }

    for (int i = n; i < n + m; i++)
    {
        pairs[i].first = arr2[i - n];
        pairs[i].second = 2;
    }

    sort(pairs.begin(), pairs.end());

    int minimumDiff = INT_MAX;
    pair<int, int> minimumPair;
    for (int i = 0; i < pairs.size() - 1; i++)
    {
        int currValue = pairs[i].first, currOrigin = pairs[i].second;
        int nextValue = pairs[i + 1].first, nextOrigin = pairs[i + 1].second;

        if (currOrigin != nextOrigin)
        {
            int currDiff = abs(currValue - nextValue);
            if (currDiff < minimumDiff)
            {
                minimumDiff = currDiff;
                minimumPair = make_pair(currValue, nextValue);
            }
        }
    }

    return minimumPair;
}

pair<int, int> minimumDifferenceSets(vector<int> arr1, vector<int> arr2)
{
    vector<int> allValues;
    unordered_set<int> arr1Values(begin(arr1), end(arr1));
    unordered_set<int> arr2Values(begin(arr2), end(arr2));

    for (auto num : arr1)
        allValues.push_back(num);

    for (auto num : arr2)
        allValues.push_back(num);

    sort(allValues.begin(), allValues.end());

    int n = allValues.size();
    int minimumDiff = INT_MAX;
    pair<int, int> minimumPair;
    for (int i = 0; i < n - 1; i++)
    {
        int currValue = allValues[i];
        int nextValue = allValues[i + 1];

        bool currInArr1 = arr1Values.find(currValue) != arr1Values.end();
        bool nextInArr2 = arr2Values.find(nextValue) != arr2Values.end();
        if (currInArr1 && nextInArr2)
        {
            int currDiff = abs(currValue - nextValue);
            if (currDiff < minimumDiff)
            {
                minimumDiff = currDiff;
                minimumPair = make_pair(currValue, nextValue);
            }
        }
    }

    return minimumPair;
}

pair<int, int> minimumDifferenceSort(vector<int> arr1, vector<int> arr2)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // Size of both arrays.
    int n = arr1.size();
    int m = arr2.size();

    // Indices to traverse both arrays.
    int i = 0, j = 0;

    // Store the result and the minimum difference.
    int minimumDiff = INT_MAX;
    pair<int, int> minimumPair;
    while (i < n && j < m)
    {
        int currentDiff = abs(arr1[i] - arr2[j]);

        if (currentDiff < minimumDiff)
        {
            minimumDiff = currentDiff;
            minimumPair = make_pair(arr1[i], arr2[j]);
        }

        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    return minimumPair;
}

int main()
{
    vector<int> arr1{23, 5, 10, 17, 30};
    vector<int> arr2{26, 134, 135, 14, 19};
    pair<int, int> result = minimumDifferenceMySolution(arr1, arr2);

    cout << "(" << result.first << ", " << result.second << ")" << endl;

    return 0;
}
