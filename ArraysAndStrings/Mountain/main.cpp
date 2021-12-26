#include <iostream>
#include <vector>
using namespace std;

int highestMountain(vector<int> arr)
{
    int n = arr.size();
    int largest = 0;

    for (int i = 1; i <= n - 2;)
    {
        // Check whether arr[i] is a peak or not.
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            int count = 1;
            int j = i;

            // Count backwards (left)
            while (j >= 1 && arr[j] > arr[j - 1])
            {
                j--;
                count++;
            }

            // Count forwards (right)
            while (i <= n - 2 && arr[i] > arr[i + 1])
            {
                i++;
                count++;
            }

            largest = max(largest, count);
        }
        else
        {
            i++;
        }
    }

    return largest;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highestMountain(arr) << endl;

    return 0;
}
