#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

int maxSubarraySumKadane(vector<int> arr)
{
    int n = arr.size();
    int ans = 0, currSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currSum + arr[i] > 0)
            currSum += arr[i];
        else
            currSum = 0;

        ans = max(ans, currSum);
    }

    return ans;
}

int maxSubarraySumOn2(vector<int> arr)
{
    int n = arr.size();

    int ans = INT_MIN;
    for (int startIdx = 0; startIdx < n; startIdx++)
    {
        int subarraySum = 0;
        for (int subarraySize = 1; subarraySize <= n; subarraySize++)
        {
            if (startIdx + subarraySize > n)
                break;

            subarraySum += arr[startIdx + subarraySize - 1];
            ans = max(ans, subarraySum);
        }
    }

    return ans;
}

int maxSubarraySumBruteforce(vector<int> arr)
{
    int n = arr.size();

    int ans = INT_MIN;
    int subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                subarraySum += arr[k];
            }

            ans = max(ans, subarraySum);
            subarraySum = 0;
        }
    }

    return ans;
}

int maxSubarraySumRecursion(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];

    int m = n / 2;

    vector<int> leftSubarray(arr.begin(), arr.begin() + m);
    vector<int> rightSubarray(arr.begin() + m, arr.end());

    int leftMSS = maxSubarraySumRecursion(leftSubarray);
    int rightMSS = maxSubarraySumRecursion(rightSubarray);

    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int subarraySum = 0;
    for (int i = m; i < n; i++)
    {
        subarraySum += arr[i];
        rightSum = max(rightSum, subarraySum);
    }

    subarraySum = 0;
    for (int i = m - 1; i > -1; i--)
    {
        subarraySum += arr[i];
        leftSum = max(leftSum, subarraySum);
    }

    int ans = max(leftMSS, rightMSS);
    return max(ans, leftSum + rightSum);
}

int main()
{
    vector<int> arr{-1, 2, 3, 4, -2, 6, -8, 3};
    cout << maxSubarraySumKadane(arr) << endl;
}
