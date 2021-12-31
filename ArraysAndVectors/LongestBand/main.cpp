#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;

    // Data inside a Set
    for (int x : arr)
        s.insert(x);

    int largestLen = 1;
    // Iterate over the array
    for (auto element : s)
    {
        int prev = element - 1;

        if (s.find(prev) == s.end())
        {
            // Find entire band / chain starting from element
            int next = element + 1;
            int count = 1;

            while (s.find(next) != s.end())
            {
                next++;
                count++;
            }

            if (count > largestLen)
                largestLen = count;
        }
    }

    return largestLen;
}

int main()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longestBand(arr) << endl;
    return 0;
}
