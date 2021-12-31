#include <iostream>
#include <vector>
using namespace std;

int trappedWaterArrays(vector<int> heights)
{
    int n = heights.size();
    if (n <= 2)
        return 0;

    // Left Max, Right Max
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    // Water
    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - heights[i];

    return water;
}

int trappedWater(vector<int> heights)
{
    int n = heights.size();
    int totalUnits = 0;

    for (int i = 0; i < n; i++)
    {
        int j;
        int left = 0;
        int right = 0;

        // Calculate largest height to the left (inclusive).
        j = i;
        while (j > -1)
        {
            left = max(left, heights[j]);
            j--;
        }

        j = i;
        while (j < n)
        {
            right = max(right, heights[j]);
            j++;
        }

        totalUnits += min(left, right) - heights[i];
    }

    return totalUnits;
}

int main()
{
    vector<int> water{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedWater(water) << endl;

    return 0;
}
