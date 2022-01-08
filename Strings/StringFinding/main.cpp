#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stringSearch(string big, string small)
{
    vector<int> result = {};
    int index = big.find(small);
    while (index != -1)
    {
        result.push_back(index);
        index = big.find(small, index + 1);
    }

    return result;
}

int main()
{
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    vector<int> occurrences = stringSearch(bigString, smallString);

    for (auto index : occurrences)
        cout << index << ", ";
    cout << endl;

    return 0;
}
