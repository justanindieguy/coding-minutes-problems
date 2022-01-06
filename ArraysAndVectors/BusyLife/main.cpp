#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int busyLife(vector<pair<int, int>> activities)
{
    sort(activities.begin(), activities.end(), compare);

    int n = activities.size();
    int endingTime = activities[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        int startTime = activities[i].first;
        if (endingTime <= startTime)
        {
            endingTime = activities[i].second;
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> activities{{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};
    cout << busyLife(activities) << endl;

    return 0;
}
