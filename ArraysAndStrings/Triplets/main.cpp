#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> getTripletsBruteForce(vector<int> arr, int Sum)
{
    vector<vector<int>> result;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == Sum)
                    result.push_back({arr[i], arr[j], arr[k]});
            }
        }
    }

    return result;
}

vector<vector<int>> getTripletsPairSum(vector<int> arr, int Sum)
{
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = Sum - arr[i];
        unordered_set<int> s;

        for (int j = i + 1; j < arr.size(); j++)
        {
            int y = x - arr[j];

            if (s.find(y) != s.end())
                result.push_back({arr[i], arr[j], y});

            s.insert(arr[j]);
        }
    }

    return result;
}

vector<vector<int>> getTripletsPairSumSort(vector<int> arr, int Sum)
{

    int n = arr.size();
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    // Pick every arr[i], solve pair sum for remaining part.
    for (int i = 0; i < n - 3; i++)
    {
        int j = i + 1; // First element
        int k = n - 1; // Last  element

        // Two pointer approach
        while (j < k)
        {
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];

            if (currentSum == Sum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (currentSum > Sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 18;

    auto result = getTripletsPairSum(arr, S);

    for (auto vector : result)
    {
        for (auto number : vector)
        {
            cout << number << ", ";
        }
        cout << endl;
    }

    return 0;
}
