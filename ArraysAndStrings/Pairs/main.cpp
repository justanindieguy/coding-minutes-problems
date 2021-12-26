#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum)
{
    // Logic
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = Sum - arr[i];

        if (s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }

        // Insert the current number inside set
        s.insert(arr[i]);
    }

    return {};
}

vector<int> pairSumBruteForce(vector<int> arr, int Sum)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i == j)
            {
                continue;
            }

            if (arr[i] + arr[j] == Sum)
            {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result;
            }
        }
    }

    return {};
}

int main()
{
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int S = 4;

    auto p = pairSum(arr, S);
    if (p.size() == 0)
        cout << "No such pair." << endl;
    else
        cout << p[0] << "," << p[1] << endl;

    return 0;
}
