#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMinimumSwaps(vector<int> arr)
{
    // Know the actual positions of elements (sorting)
    // Store the current indices
    int n = arr.size();
    vector<pair<int, int>> ap(n);
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap.begin(), ap.end());

    // Build the main logic
    int ans = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        // If element is visited or element is in the right position
        int oldPosition = ap[i].second;
        if (visited[i] == true || oldPosition == i)
            continue;

        // Visiting the element (index) for first time
        int node = i;
        int cycle = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int nextNode = ap[node].second;
            node = nextNode;
            cycle += 1;
        }
        ans += cycle - 1;
    }

    return ans;
}

int main()
{
    vector<int> arr{2, 4, 5, 1, 3};
    cout << countMinimumSwaps(arr) << endl;
    return 0;
}
